#include <bits/stdc++.h>
#define INF 999999999

using namespace std;

int n, m;
int dp[101][101];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    }   
    
    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        dp[a][b] = min(dp[a][b], w);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == INF) cout << 0 << ' ';
            else cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}