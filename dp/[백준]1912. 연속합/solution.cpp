#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, s, dp, res;
    cin >> n;

    cin >> s;
    dp = res = s;
    for (int i = 1; i < n; i++) {
        cin >> s;
        dp = max(dp + s, s);
        res = max(res, dp);
    }
    cout << res;
}

// 첫 풀이
#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int main() {
    int n, res;
    cin >> n;
    vector<int> v(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    res = dp[0] = v[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(0, max(dp[i - 1], v[i - 1])) + v[i];
        res = max(res, dp[i]);
    }
    cout << res;
}