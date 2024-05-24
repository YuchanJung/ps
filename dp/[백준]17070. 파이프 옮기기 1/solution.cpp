#include <bits/stdc++.h>

using namespace std;

int n;
int a[16][16];
int dp[16][16][3]; // 가로, 세로, 대각선
 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    
    dp[0][1][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 2; j < n; j++) {
            if (i == 0) {
                if (a[i][j] == 1) break;
                dp[i][j][0] = 1;
            }
            else {
                if (a[i][j] == 1) continue;
                dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
                dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
                if (a[i][j - 1] != 1 && a[i - 1][j] != 1) {
                    dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
                }
            }
        }
        
    }

    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
}