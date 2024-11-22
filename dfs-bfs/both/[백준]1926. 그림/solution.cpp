#include <bits/stdc++.h>
using namespace std;
using V = vector<int>;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, k, cnt;
int arr[500][500];
int visited[500][500];
queue<V> q;

int bfs(int x, int y) {
    int res = 1;
    visited[x][y] = 1;
    q.push({x, y});
    while (!q.empty()) {
        V v = q.front(); q.pop();
        int x = v[0], y = v[1];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (arr[nx][ny] && !visited[nx][ny]) {
                res += 1;
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] && !visited[i][j]) {
                cnt += 1;
                k = max(k, bfs(i, j));
            }
        }
    }
    cout << cnt << '\n' << k;
}