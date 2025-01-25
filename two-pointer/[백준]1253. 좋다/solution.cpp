#include <bits/stdc++.h>
using namespace std;

int n, res, arr[2000];

bool check(int x, int i) {
    int l = 0, r = n - 1;
    while (l < r) {
        if (l == i) {
            l++;
            continue;
        }
        if (r == i) {
            r--;
            continue;
        }
        int s = arr[l] + arr[r];
        if (s == x) return true;
        if (s > x) r--;
        else l++;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        if (check(arr[i], i))
            res++;
    }
    cout << res;
}