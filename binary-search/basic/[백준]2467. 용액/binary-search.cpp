#include <bits/stdc++.h>

using namespace std;

int n, a, b, res = 2000000000;
int arr[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int t = -arr[i];
        int idx = lower_bound(arr, arr + n, t) - arr;
        if (idx == n) idx--;
        int x1, x2;
        x1 = abs(arr[i] + arr[idx]);
        x2 = abs(arr[i] + arr[idx > 0 ? idx - 1 : idx]);

        if (x1 <= x2 && res > x1 && i != idx) {
            res = x1;
            a = arr[i]; b = arr[idx];
        }
        else if (x1 > x2 && res > x2 && i != idx - 1) {
            res = x2;
            a = arr[i]; b = arr[idx - 1];
        }
    }
    if (a < b) cout << a << ' ' << b;
    else cout << b << ' ' << a;
}