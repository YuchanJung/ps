#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
    int x, y;
};

int dx[4] = {0, 0, -1, 1}; // 좌우상하
int dy[4] = {-1, 1, 0, 0};

int N, M, K, res, cnt;
int maze[11][11];
int ps[11][11]; // 사람 수 기록용
Pos ex;
int rr, rc, rs; // 회전

void move() {
    vector<vector<int>> tmp;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            if (ps[x][y] > 0) tmp.push_back({x, y, ps[x][y]});
        }
    }
    for (auto v: tmp) {
        int x = v[0], y = v[1], num = v[2];
        if (ps[x][y] == 0) continue;
        int dist = abs(ex.x - x) + abs(ex.y - y);
        int nd = -1; 
        // 최단 거리 가까워지는 칸 찾기
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx <= 0 || ny <= 0 || nx > N || ny > N || maze[nx][ny] > 0) continue;
            if (dist >= abs(ex.x - nx) + abs(ex.y - ny)) {
                nd = d;
            }
        }
        if (nd == -1) continue;
        // 이동
        int nx = x + dx[nd];
        int ny = y + dy[nd];
        res += num;
        if (ex.x == nx && ex.y == ny) cnt -= num;
        else ps[nx][ny] += num;
        ps[x][y] -= num;
    }
}

void find_rec() {
    rr = -1; rc = -1; rs = 0;
    for (int s = 2; s <= N; s++) {
        int r = 1, c = 1;
        bool find = false;
        while (r + s - 1 <= N) {
            bool isEx = false, isP = false;
            for (int i = r; i < r + s; i++) {
                for (int j = c; j < c + s; j++) {
                    if (maze[i][j] == -1) isEx = true; // 출구 있으면
                    if (ps[i][j] > 0) isP = true; // 사람 한 명 이상 있으면
                }
            }
            if (isEx && isP) {
                find = true;
                break;
            }
            c++;
            if (c + s - 1 > N) {
                c = 1;
                r++;
            }
        }
        if (find) {
            rr = r;
            rc = c;
            rs = s;
            break;
        }
    }
}

void rotate() {
    // 회전
    int tmp[11][11], ps_tmp[11][11];
    Pos tp[11];
    for (int i = 0; i < rs; i++) {
        for (int j = 0; j < rs; j++) {
            tmp[i][j] = maze[rr + i][rc + j];
            ps_tmp[i][j] = ps[rr + i][rc + j];
        }
    }
    for (int i = 0; i < rs; i++) {
        for (int j = 0; j < rs; j++) {
            // maze 회전
            int v = tmp[rs - j - 1][i];
            if (v == -1) {
                ex.x = rr + i;
                ex.y = rc + j;
            }
            if (v > 0) v--;
            maze[rr + i][rc + j] = v;

            // ps 회전, 사람들 pos 갱신
            v =  ps_tmp[rs - j - 1][i];      
            ps[rr + i][rc + j] = v;
        }
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> maze[i][j];
    for (int i = 1; i <= M; i++) {
        int px, py;
        cin >> px >> py;
        ps[px][py] += 1;
    }
    cin >> ex.x >> ex.y;
    maze[ex.x][ex.y] = -1;
    cnt = M;

    while (K--) {
        move();
        if (cnt == 0) break;
        find_rec();
        rotate();
    }
    cout << res << '\n' << ex.x << ' ' << ex.y;
}