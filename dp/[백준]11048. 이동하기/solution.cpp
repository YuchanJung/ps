// 방향이 무조건 +1 이기 때문에 dfs 필요 없음
#include <bits/stdc++.h>

using namespace std;


int n, m;
int arr[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            arr[i][j] += max(arr[i - 1][j], arr[i][j - 1]);
        }
    }
    cout << arr[n][m];
}

// dfs
#include <bits/stdc++.h>

using namespace std;

int dx[3] = {1, 0};
int dy[3] = {0, 1};
int n, m;
int arr[1000][1000];
int dp[1000][1000];

int dfs(int x, int y) {
    if (x == n - 1 && y == m - 1) return arr[x][y];
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        dp[x][y] = max(dp[x][y], dfs(nx, ny));
    }
    dp[x][y] += arr[x][y];
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(0, 0);
}
