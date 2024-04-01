#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n, m, res = 0;
int flag = 1;
int arr[1000][1000];
queue<vector<int>> q;
int cnt = 0;

void bfs() {
    while(!q.empty()) {
        if (cnt == 0) break;
        vector<int> now = q.front(); q.pop();
        int x = now[0];
        int y = now[1];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (arr[nx][ny] == 0) {
                arr[nx][ny] = arr[x][y] + 1;
                q.push({nx, ny}); 
                cnt--;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) q.push({i, j});
            if (arr[i][j] == 0) cnt++;
        }
    }
    bfs();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) flag = 0;
            res = max(res, arr[i][j]);
        }
    }
    if (flag) cout << res - 1;
    else cout << -1;
}