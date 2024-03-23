#include <cstdio>
#include <algorithm>
#define MAX 300

using namespace std;

int arr[MAX + 1];
int dp[MAX + 1][2] = {0};
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    dp[1][0] = arr[1]; dp[1][1] = 0;
    dp[2][0] = arr[1] + arr[2]; dp[2][1] = arr[2];

    for (int i = 3; i <= n; i++) {
        dp[i][0] = dp[i - 1][1] + arr[i];
        dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + arr[i];
    }

    printf("%d", max(dp[n][0], dp[n][1]));
}