#include <bits/stdc++.h>
#define H 100
#define N 100
#define M 100

using namespace std;

int m, n, h, s;
int arr[H][M][N];
queue<vector<int>> q;
int d[3][6] = {{1, -1, 0, 0, 0, 0}, {0, 0, 1, -1, 0, 0}, {0, 0, 0, 0, 1, -1}};

int bfs() {
    while (!q.empty()) {
        vector<int> v = q.front(); q.pop();
        int _h = v[0], x = v[1], y = v[2]; 
        for (int i = 0; i < 6; i++) {
            int nh = _h + d[0][i];
            int nx = x + d[1][i];
            int ny = y + d[2][i];
            if (nh < 0 || nx < 0 || ny < 0 || nh >= h || nx >= n || ny >= m) continue;
            if (arr[nh][nx][ny] == 0) {
                arr[nh][nx][ny] = arr[_h][x][y] + 1;
                q.push({nh, nx, ny});
                if (--s == 0) return arr[nh][nx][ny] - 1;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n >> h;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[k][i][j];
                if (arr[k][i][j] == 0) s++; // 개수
                else if (arr[k][i][j] == 1) q.push({k, i, j});
            }
        }
    }
    if (s == 0) cout << 0;
    else cout << bfs();
}