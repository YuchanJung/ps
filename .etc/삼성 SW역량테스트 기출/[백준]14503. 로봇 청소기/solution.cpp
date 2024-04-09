#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, r, c, d;
int arr[50][50];
int res;

void solve(int r, int c, int d) {
    while (true) {
        if (!arr[r][c]) {
            arr[r][c] = 2; // 청소
            res++;
        }
        bool clean = true;
        int nd, nx, ny;
        for (int i = 1; i <= 4; i++) {
            nd = (d - i + 4) % 4;
            nx = r + dx[nd];
            ny = c + dy[nd];
            if (arr[nx][ny] == 0) {
                r = nx; c = ny; d = nd;
                clean = false;
                break;
            }
        }
        if (clean) {
            nd = (d + 2) % 4;
            nx = r + dx[nd];
            ny = c + dy[nd];
            if (arr[nx][ny] == 1) return;
            else r = nx; c = ny;
        }
    }
}

int main() {
    cin >> n >> m >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    solve(r, c, d);
    cout << res;
}