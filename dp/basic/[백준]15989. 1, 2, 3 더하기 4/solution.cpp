#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    int dp[10000] = { 0, 1, 2, 3, };

    for (int i = 4; i <= 10000; i++) {
        dp[i] = dp[i - 3] + i / 2 + 1;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}