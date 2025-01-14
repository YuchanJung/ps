#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll res, sum, s;
ll mods[1000], n, m;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        sum += s;
        ++mods[sum % m];
    }
    res = mods[0];
    for (int i = 0; i < m; i++) {
        res += mods[i] * (mods[i] - 1) / 2;
    }
    cout << res;
}


// 누적 합

// 1 2 3 1 2
// 1 3 6 7 9

// 1 0 0 1 0