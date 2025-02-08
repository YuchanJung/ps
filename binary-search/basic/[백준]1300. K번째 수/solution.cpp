#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k, res;

int main() {
    cin >> n >> k;
    ll l = 1, r = k;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += min(mid / i, n);
        }
        if (cnt >= k) {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
}