#include <bits/stdc++.h>
using namespace std;

int n, m, s, l, r;
int arr[100000];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s += arr[i];
        l = max(l, arr[i]);
    }
    r = s;
    while (l <= r) {
        int mid = (l + r) / 2;

        int k = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (k + arr[i] > mid) {
                k = 0;
                cnt++;
            }
            k += arr[i];
        }
        if (k > 0) cnt++;
        if (cnt <= m) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l;
}