#include <cstdio>
#define MAX 1000001

using namespace std;

int n;
int arr[MAX];
int dp[MAX];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    dp[n] = -1;
    for (int i = n - 1; i >= 1; i--) {
        if (arr[i] == arr[i + 1]) {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = i + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dp[i]);
    }
}