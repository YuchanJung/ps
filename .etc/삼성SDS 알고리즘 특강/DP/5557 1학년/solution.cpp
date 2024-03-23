#include <cstdio>
#include <queue>

using namespace std;

long long dp[101][21] = {0}; // n : 1 ~ 100 , 숫자 범위 0 ~ 20
int ex[101]; // `n : 1 ~ 100
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ex[i]);
    }
    
    dp[1][ex[1]] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i][j] >= 1) {
                if (j + ex[i + 1] <= 20) dp[i + 1][j + ex[i + 1]] += dp[i][j];
                if (j - ex[i + 1] >= 0) dp[i + 1][j - ex[i + 1]] += dp[i][j];
            } 
        }
    }

    printf("%lld", dp[n - 1][ex[n]]);
}