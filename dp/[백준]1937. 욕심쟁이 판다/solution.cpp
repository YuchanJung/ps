#include <bits/stdc++.h>

using namespace std;

int n, res;
int arr[500][500];
int dp[500][500];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (arr[nx][ny] > arr[x][y]) {
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
        }
    }
    if (dp[x][y] == -1) dp[x][y] = 1;
    return dp[x][y];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, dfs(i, j));
        }
    }
    cout << res;
}