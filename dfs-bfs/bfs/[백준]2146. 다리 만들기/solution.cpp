#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, cnt, res = 1e6;
int arr[100][100], visited[100][100];
queue<vector<int>> q;

bool isBorder(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (arr[nx][ny] == 0) return true;
    }
    return false;
}

void dfs(int x, int y, int k) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;
        if (arr[nx][ny]) {
            arr[nx][ny] = k;
            visited[nx][ny] = 1;
            dfs(nx, ny, k);
        }
    }
}

int bfs(int sx, int sy) {
    visited[sx][sy] = 1;
    q.push({sx, sy});
    while (!q.empty()) {
        vector<int> v = q.front(); q.pop();
        int x = v[0], y = v[1];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;
            if (arr[nx][ny] == 0) {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
            else if (arr[nx][ny] != arr[sx][sy]) {
                return visited[x][y] - 1;
            }
        }
    }
    return 1e9;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    // 구역 배정
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!arr[i][j] || visited[i][j]) continue;
            arr[i][j] = ++cnt;
            visited[i][j] = 1;
            dfs(i, j, cnt);
        }
    }
    // 다리 찾기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!arr[i][j] || !isBorder(i, j)) continue;
            memset(visited, 0, sizeof(visited));
            while (!q.empty()) q.pop();
            res = min(res, bfs(i, j));
        }
    }
    cout << res;
}