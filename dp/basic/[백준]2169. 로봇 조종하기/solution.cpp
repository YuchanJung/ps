#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1000][1000];
int dp[1000][1000];
int p[1000], q[1000];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    dp[0][0] = arr[0][0];
    for (int i = 1; i < m; i++)
        dp[0][i] = dp[0][i - 1] + arr[0][i];
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = dp[i - 1][j] + arr[i][j];
            p[j] = q[j] = dp[i][j];
        }

        for (int j = 1; j < m; j++) {
            q[j] = max(q[j], q[j - 1] + arr[i][j]);
            dp[i][j] = max(dp[i][j], q[j]);
        }
        // if (i == n - 1) continue;
        for (int j = m - 2; j >= 0; j--) {
            p[j] = max(p[j], p[j + 1] + arr[i][j]);
            dp[i][j] = max(dp[i][j], p[j]);
        }
    }
    cout << dp[n - 1][m - 1];
}