#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    int dp[1001][1001] = {0};
    cin >> s1 >> s2;
    int p = s1.size(), q = s2.size();;
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= q; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    cout << dp[p][q];
}