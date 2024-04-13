#include <iostream>
#include <queue>

using namespace std;

struct Ball {
    int x, y, m, s, d;
};

int dx[8] = {-1, -1 ,0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int N, M, K, res;
int r, c, m, s, d;
int cnt[51][51];
Ball arr[51][51];
queue<Ball> q;

void print_arr() {
    cout << "=====================================\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << cnt[i][j] << ' ' << arr[i][j].m << ' ' << arr[i][j].s << ' ' <<  arr[i][j].d << " | ";
        }
        cout << '\n';
    }
}

void move() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            arr[i][j] = {i, j, 0, 0, 0};
            cnt[i][j] = 0;
        }
    }
    // Ball queue에서 하나씩 빼서 이동
    int l = q.size();
    for (int i = 0; i < l; i++) {
        Ball b = q.front(); q.pop();
        int x = b.x, y = b.y; 
        int nx = x + dx[b.d] * b.s;
        int ny = y + dy[b.d] * b.s;
        while (nx <= 0) nx += N;
        while (nx > N) nx -= N;
        while (ny <= 0) ny += N;
        while (ny > N) ny -= N;
        if (cnt[nx][ny] >= 1) { // 이미 있으면 방향 조건 기록
            if (arr[nx][ny].d % 2 != b.d % 2) arr[nx][ny].d = -1;
        } else {
            arr[nx][ny].d += b.d; // arr[nx][ny].d = b.d;
        }
        cnt[nx][ny]++;
        arr[nx][ny].m += b.m;
        arr[nx][ny].s += b.s;
    }

    // print_arr();

    // queue push
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (cnt[i][j] == 1) {
                q.push(arr[i][j]);
            }
            else if (cnt[i][j] > 1) { // 4개로 나눔
                int td[4] = {0, 2, 4, 6};
                if (arr[i][j].d == - 1) {
                    for (int t = 0; t < 4; t++) td[t]++;
                }
                for (int t = 0; t < 4; t++) {
                    Ball b = {i, j, arr[i][j].m / 5, arr[i][j].s / cnt[i][j], td[t]};
                    if (b.m > 0) q.push(b);
                }
            }
        }
    }
}


int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            arr[i][j] = {i, j, 0, 0, 0};

    for (int i = 0; i < M; i++) {
        cin >> r >> c >> m >> s >> d;
        Ball b = {r, c, m, s, d};
        q.push(b);
    }
    while (K--) move();
    while (!q.empty()) {
        Ball b = q.front(); q.pop();
        res += b.m;
    }
    cout << res;
}