#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m, res;
int arr[50][50];
queue<vector<int>> q;

void bfs(int i, int j) {
    int d[50][50] = {0};
    q.push({i, j});
    d[i][j] = 1;
    while(!q.empty()) {
        int x = q.front()[0], y = q.front()[1]; q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || d[nx][ny] != 0) continue;
            if (arr[nx][ny] == 1) {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
                res = max(res, d[nx][ny]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'W') arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 1)
                bfs(i, j);

    cout << res - 1;
}