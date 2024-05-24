// 정리
#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int dp[MAX + 1];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= MAX; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n];
}

/* 첫 코드
#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int dp[MAX + 1];
int n;

int main() {
    cin >> n;
    dp[1] = 1;
    for (int i = 1; i <= MAX; i++) dp[i] = i;
    for (int i = 1; i * i <= MAX; i++) dp[i * i] = 1; 

    for (int i = 2; i <= MAX; i++) {
        int t = i;
        int k = 1;
        while (t - k * k > 0) {
            dp[i] = min(dp[i], dp[t - k * k] + 1);
            k++;
        }
    }
    cout << dp[n];
}
*/