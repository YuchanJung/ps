#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n, m, x, y;
int arr[1100][1100];
int res[1100][1100];
queue<vector<int>> q;

void bfs(int x, int y) {
    res[x][y] = 1;
    q.push({x, y});
    while (!q.empty()) {
        vector<int> now = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now[0] + dx[i];
            int ny = now[1] + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || res[nx][ny]) continue;
            if (arr[nx][ny] == 0) continue;
            res[nx][ny] = res[now[0]][now[1]] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                x = i;
                y = j;
            }
        }
    }
    bfs(x, y);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (res[i][j] == 0) {
                if (arr[i][j] == 0) cout << "0 ";
                else cout << "-1 ";
            }
            else cout << res[i][j] - 1 << ' ';
        }
        cout << '\n';
    }
}