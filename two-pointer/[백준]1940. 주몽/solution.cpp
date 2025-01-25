#include <bits/stdc++.h>
using namespace std;

int n, m, res, l, r;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    vector<int> v(n);
    for (auto &n: v) cin >> n;
    sort(v.begin(), v.end());

    r = n - 1;
    while (l < r) {
        int s = v[l] + v[r];
        if (s == m) {
            res++;
            l++;
        }
        else if (s > m) r--;
        else l++;
    }
    cout << res;
}