// dp
#include <bits/stdc++.h>

using namespace std;

int n, t[16], p[16], dp[21];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + t[i]; j < 22; j++) {
            dp[j] = max(dp[j], dp[i] + p[i]);
        }
    }

    cout << dp[n + 1];
}

// 원래 풀이 : brute force
#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> v;

int find(int idx) {
    if (idx >=n) return 0;
    if (idx + v[idx][0] > n) return find(idx + 1);
    
    int temp1 = v[idx][1] + find(idx + v[idx][0]);
    int temp2 = find(idx + 1);

    return max(temp1, temp2);
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int t, p;
        cin >> t >> p;
        v.push_back({t, p});
    }

    cout << find(0);
}