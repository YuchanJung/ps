#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n{}, q{}, k{};
    cin >> n >> q;
    vector<int> v(n);
    vector<int> cnt(n);
    vector<int> kex_list(q);

    for (auto& x : v) cin >> x;
    for (auto& x : kex_list) cin >> x;

    sort(v.begin(), v.end());

    cnt[0] = v[0];
    for (int i = 1; i < n; i++) {
        cnt[i] = cnt[i - 1] + v[i] - v[i - 1] - 1;
    }

    for (int i = 0; i < q; i++) {
        int k = kex_list[i];
        int res{};
        int idx = lower_bound(cnt.begin(), cnt.end(), k) - cnt.begin();
        if (idx == 0) {
            res = v[idx] - (cnt[idx] - k + 1); 
        } else {
            res = v[idx - 1] + k - cnt[idx - 1];
        }
        cout << res << " ";
    }
}