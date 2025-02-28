#include <bits/stdc++.h>
using namespace std;

int t, n, l, res;
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> l;
            pq.push(l);
        }
        int a, b;
        a = b = pq.top(); pq.pop();
        while (!pq.empty()) {
            int k = pq.top(); pq.pop();
            if (a > b) {
                res = max(res, a - k);
                a = k;
            }
            else {
                res = max(res, b - k);
                b = k;
            }
        }
        res = max(res, abs(a - b));
        cout << res << '\n';
        res = 0;
    }
}