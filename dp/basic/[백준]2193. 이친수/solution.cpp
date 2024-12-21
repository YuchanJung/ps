#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long dp[91][2] = {0};
    cin >> n;
    dp[1][1] = dp[2][0] = 1;
    for (int i = 3; i <= 90; i++) {
        dp[i][1] = dp[i - 1][0];
        dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
    }
    cout << dp[n][0] + dp[n][1];
}