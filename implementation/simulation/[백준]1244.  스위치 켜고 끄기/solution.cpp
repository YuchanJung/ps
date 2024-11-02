#include <bits/stdc++.h>

using namespace std;

int n, k, s, t;

int main() {
    cin >> n;
    vector<int> v(n);
    for (auto &i: v) cin >> i;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> s >> t;
        if (s == 1) {
            int temp = t;
            t -= 1;
            while (t < n) {
                v[t] = !v[t];
                t += temp;
            }
        }
        else {
            t -= 1;
            v[t] = !v[t];
            int i = 1;
            while (t - i >= 0 && t + i < n) {
                if (v[t - i] == v[t + i]) {
                    v[t - i] = !v[t - i];
                    v[t + i] = !v[t + i];
                    i++;
                }
                else break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i - 1] << ' ';
        if (i % 20 == 0) cout << '\n';
    }
}