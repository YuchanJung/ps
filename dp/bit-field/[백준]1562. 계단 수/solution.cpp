#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;

int n;
int dp[101][10][1025];
int res;

int main() {
    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    for (int i = 1; i < 100; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < 1024; k++) {
                if (dp[i][j][k] == 0) continue;
            
                if (j > 0) {
                    int v = (1 << (j - 1)) | k;
                    dp[i + 1][j - 1][v] = (dp[i + 1][j - 1][v] + dp[i][j][k]) % MOD;
                }
                if (j < 9) {
                    int v = (1 << (j + 1)) | k;
                    dp[i + 1][j + 1][v] = (dp[i + 1][j + 1][v] + dp[i][j][k]) % MOD;
                }
            }
        }
    }
    cin >> n;
    for (int i = 0; i <= 9; i++) {
        res = (res + dp[n][i][1023]) % MOD;
    }
    cout << res;
}