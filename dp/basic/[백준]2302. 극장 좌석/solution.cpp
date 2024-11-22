#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x, res = 1;
    int arr[41] = {1, 1, 2};
    for (int i = 3; i <= 40; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    cin >> n >> m;
    int idx = 1;
    while (m--) {
        cin >> x;
        res *= arr[x - idx];
        idx = x + 1;
    }
    res *= arr[n - idx + 1];
    cout << res;
}