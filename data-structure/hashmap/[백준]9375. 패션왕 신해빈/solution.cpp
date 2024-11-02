#include <bits/stdc++.h>

using namespace std;

int t, n;
string s, k;
map<string, int> mp;

int main() {
    cin >> t;
    while (t--) {
        int res = 1;
        mp.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s >> k;
            if (mp.find(k) != mp.end()) mp[k]++;
            else mp[k] = 1;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            res *= it->second + 1;
        }
        cout << res - 1 << '\n';
    }
}