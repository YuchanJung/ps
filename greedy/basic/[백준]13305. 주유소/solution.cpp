#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    int m, n, res = 0;
    cin >> n >> m;
    int x, t = 0;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (i == 0) res = max(res, x);
        if (i == m - 1) res = max(res, n - x);
        else res = max(res, (x - t + 1) / 2);
        t = x;
    }
    cout << res;
}