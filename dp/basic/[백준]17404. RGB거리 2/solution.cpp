#include <bits/stdc++.h>

using namespace std;

int inf = 1e9;
int n, res = inf;
int arr[1001][3];
int dp[1001][3];

int main() {    
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 3; i++) {
            if (k == i) dp[1][i] = arr[1][i];
            else dp[1][i] = inf;
        }
        
        for (int i = 2; i <= n; i++) {
            dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]); 
            dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]); 
        }

        for (int i = 0; i < 3; i++) {
            if (k == i) continue;
            res = min(res, dp[n][i]);
        }

    }
    cout << res;
}