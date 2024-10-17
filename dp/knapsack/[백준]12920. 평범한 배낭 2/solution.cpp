#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int n, m;
int v, c, k;
vector<vector<int>> p = {{0, 0}};
int l;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> v >> c >> k;
        for (int i = 1; k > i; i <<= 1) {
            p.push_back({v * i, c * i});
            k -= i;
        }
        p.push_back({v * k, c * k});
    }

    l = p.size();
    vector<vector <int>> dp(l, vector<int>(m + 1, 0));
    for (int i = 1; i < l; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= p[i][0])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - p[i][0]] + p[i][1]);
        }
    }
    cout << dp[l - 1][m];
}