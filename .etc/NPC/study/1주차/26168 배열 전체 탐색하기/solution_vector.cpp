#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n{}, m{};
    cin >> n >> m;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    while (m--) {
        ll c{}, x{}, y{};
        cin >> c >> x;
        int res{};
        if (c == 1) {
            res = v.end() - lower_bound(v.begin(), v.end(), x);
        }
        else if (c == 2) {
            res = v.end() - upper_bound(v.begin(), v.end(), x);
        }
        else {
            cin >> y;
            res = upper_bound(v.begin(), v.end(), y) - lower_bound(v.begin(), v.end(), x);
        }
        cout << res << "\n";
    }
    return 0;
}