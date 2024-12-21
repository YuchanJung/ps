#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, s;
    int arr[10001] = {0};
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s > 10000) continue;
        arr[s] += 1;
        for (int j = s + 1; j <= 10000; j++) {
            arr[j] += arr[j - s];
        }
    }
    cout << arr[k];
}