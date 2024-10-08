#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001], dp[1001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = max({dp[i], arr[i], dp[j] + dp[i - j]});
        }
    }
    cout << dp[n];
}