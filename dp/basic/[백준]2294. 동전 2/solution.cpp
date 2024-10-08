#include <bits/stdc++.h>
#define INF 2e9

using namespace std;

int main() {
    int n, k, s;
    int arr[10001] = {0};
    cin >> n >> k;

    for (int i = 1; i <= 10000; i++) arr[i] = INF;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = s; j <= 10000; j++) {
            arr[j] = min(arr[j], arr[j - s] + 1);
        }
    }
    if (arr[k] != INF) cout << arr[k];
    else cout << -1;
}