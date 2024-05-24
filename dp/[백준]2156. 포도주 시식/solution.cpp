#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, res = 0;
    int arr[10000];
    int dp[10000][3] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0][1] = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = dp[i - 1][0] + arr[i];
        dp[i][2] = dp[i - 1][1] + arr[i];
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}