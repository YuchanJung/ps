#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int m, n;
int arr[500][500], dp[500][500];

int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    if (x == m - 1 && y == n - 1) return 1;

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if (arr[x][y] > arr[nx][ny])
            dp[x][y] += dfs(nx, ny);
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(0, 0);
}