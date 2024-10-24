#include <bits/stdc++.h>
#define M 1000

using namespace std;

int dx[4] = {1, -1 ,0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
int arr[M][M];
int visited[M][M];
queue<tuple<int, int, int, int>> q;

int bfs() {
    if (n == 1 && m == 1) return 1;
    visited[0][0] = 0b11;
    q.push({0, 0, 0, 1});
    while (!q.empty()) {
        int x, y, w, d;
        tie(x, y, w, d) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (arr[nx][ny] == 0) {
                if ((visited[nx][ny] & (1 << w)) != 0) continue;
                if (nx == n - 1 && ny == m - 1) return d + 1;
                visited[nx][ny] |= (1 << w);
                q.push({nx, ny, w, d + 1}); 
            }
            else if (w == 0) {
                visited[nx][ny] |= 0b10;
                q.push({nx, ny, 1, d + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            arr[i][j] = s[j] - '0';
    }
    cout << bfs();
}