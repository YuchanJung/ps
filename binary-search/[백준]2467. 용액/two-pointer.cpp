#include <bits/stdc++.h>

using namespace std;

int n, a, b, res = 2000000000;
int arr[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int s = 0, e = n - 1;
    while (s < e) {
        int x = arr[s] + arr[e];
        if (res > abs(x)) {
            a = s;
            b = e;
            res = abs(x);
        }
        (x > 0) ? e-- : s++;
    }
    cout << arr[a] << ' ' << arr[b];
}