#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;
int arr[100][100];
int dist[100][100];
queue<vector<int>> q; 

void bfs() {
    while(!q.empty()) {
        vector<int> v = q.front(); q.pop();
        int x = v[0]; int y = v[1];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (arr[nx][ny] == 1 && dist[nx][ny] == 0) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            } 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') arr[i][j] = 1;
        }
    }
    q.push({0, 0});
    dist[0][0] = 1;
    bfs();
    cout << dist[n - 1][m - 1];
}