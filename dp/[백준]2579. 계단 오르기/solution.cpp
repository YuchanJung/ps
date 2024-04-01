#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int arr[301] = {0};
    int dp[301][2] = {0}; // [1칸 넘는 칸, 2칸 넘는 칸]
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    dp[1][1] = arr[1];
    for (int i = 2; i <=n; i++) {
        dp[i][0] = dp[i - 1][1] + arr[i]; 
        dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + arr[i];
    }
    cout << max(dp[n][0], dp[n][1]);
}