#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
    int x, y;
};

int dx[4] = {0, 1, 0, -1}; // 우하좌상
int dy[4] = {1, 0, -1, 0};

int ax[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int ay[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int N, M, K, cnt;
int arr[11][11];
int recent[11][11];
int wx, wy, wv, sx, sy, sv;
queue<Pos> q;
int dist[11][11], minDist;
bool check[11][11];
Pos prevPos[11][11];

void pick_attacker() {
    wx = wy = -1; wv = 9999;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 0) continue; // 포탑 없음
            // 가장 약한 포탑 찾기
            bool update = false;
            if (wv > arr[i][j]) update = true;
            else if (wv == arr[i][j]) {
                if (recent[wx][wy] < recent[i][j]) update = true;
                else if (recent[wx][wy] == recent[i][j]) {
                    if (wx + wy < i + j) update = true;
                    else if (wx + wy == i + j && wy < j) update = true;
                }
            }
            if (update) {
                wv = arr[i][j];
                wx = i;
                wy = j;
            }
        }
    }
}

void pick_strongest() {
    // 가장 강한 포탑 찾기
    sx = sy = -1; sv = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i == wx && j == wy) continue;

            bool update = false;
            if (sv < arr[i][j]) update = true;
            else if (sv == arr[i][j]) {
                if (recent[sx][sy] > recent[i][j]) update = true;
                else if (recent[sx][sy] == recent[i][j]) {
                    if (sx + sy > i + j) update = true;
                    else if (sx + sy == i + j && sy > j) update = true;
                }
            }
            if (update) {
                sv = arr[i][j];
                sx = i;
                sy = j;
            }
        }
    }
}

bool find_route() {
    // init
    while(!q.empty()) q.pop();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dist[i][j] = 0;
            prevPos[i][j] = {0, 0};
        }
    }

    // 시작
    q.push({wx, wy});
    dist[wx][wy] = 1;

    while(!q.empty()) {
        Pos now = q.front(); q.pop();
        int x = now.x, y = now.y;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 반대편으로 나오기
            if (nx == 0) nx = N;
            if (ny == 0) ny = M;
            if (nx == N + 1) nx = 1;
            if (ny == M + 1) ny = 1;
            // 부서진 포탑으로 이동 불가
            if (arr[nx][ny] == 0 || dist[nx][ny] > 0) continue;
            dist[nx][ny] = dist[x][y] + 1;
            prevPos[nx][ny] = {x, y};
            q.push({nx, ny});
        }
    }
    if (dist[sx][sy] == 0) return false; // 도달 불가
    else {
        minDist = dist[sx][sy];
        return true;
    }
}

void razer_attack() {
    vector<Pos> v;
    int p = sx, q = sy;
    while (true) {
        Pos pre = prevPos[p][q];
        if (pre.x == wx && pre.y == wy) break;
        v.push_back(pre);
        p = pre.x; q = pre.y;
    }
    for (int i = 0; i < v.size(); i++) {
        Pos po = v[i];
        p = po.x; q = po.y;
        arr[p][q] -= wv / 2;
        check[p][q] = true;
        if (arr[p][q] <= 0) {
            arr[p][q] = 0;
            cnt--;
            if (cnt == 1) return;
        }
    }
    arr[sx][sy] -= wv;
    if (arr[sx][sy] <= 0) {
        arr[sx][sy] = 0;
        cnt--;
        if (cnt == 1) return;
    }
}

void power_attack() {
    arr[sx][sy] -= wv; sv -= wv;
    if (arr[sx][sy] <= 0) {
        arr[sx][sy] = 0;
        cnt--;
        if (cnt == 1) return;
    }

    check[sx][sy] = true;
    int p = sx, q = sy;

    for (int i = 0; i < 8; i++) {
        int nx = p + ax[i];
        int ny = q + ay[i];
        if (nx == 0) nx = N;
        if (ny == 0) ny = M;
        if (nx == N + 1) nx = 1;
        if (ny == M + 1) ny = 1;
        // 부서진 포탑으로 이동 불가
        if (arr[nx][ny] == 0) continue;
        // 공격자 영향 x
        if (nx == wx && ny == wy) continue;

        arr[nx][ny] -= wv / 2;
        check[nx][ny] = true;
        if (arr[nx][ny] <= 0) {
            arr[nx][ny] = 0;
            cnt--;
            if (cnt == 1) return;
        }

    }
}

void repair() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] > 0 && !check[i][j]) 
                arr[i][j] += 1;
        }
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > 0) cnt++;
        }
    }
    for (int t = 1; t <= K; t++) {
        if (cnt == 1) break;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                check[i][j] = false;
            }
        }

        pick_attacker();
        pick_strongest();

        recent[wx][wy] = t;
        arr[wx][wy] += N + M; wv += N + M;// 핸디캡 적용
        check[wx][wy] = true; // 공격 관여
        check[sx][sy] = true;
        
        
        if (find_route()) {
            razer_attack();
        } else {
            power_attack();
        }
        repair();
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            res = max(arr[i][j], res);
        }
    }
    cout << res;
}