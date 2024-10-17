#include <bits/stdc++.h>

using namespace std;

int n, k, w, v;
int dp[101][100001];
vector<vector<int>> l = {{0, 0}};

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        l.push_back({w, v});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (l[i][0] <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - l[i][0]] + l[i][1]);
        }
    }
    cout << dp[n][k];
}