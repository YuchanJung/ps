#include <bits/stdc++.h>
using namespace std;

int n, res;
int a[500000], b[500000];
unordered_map<int, int> um;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        um[b[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (um[a[i]] >= i) continue;
        res = max(res, i - um[a[i]]);
    }
    cout << res + 1;
}