#include <bits/stdc++.h>

using namespace std;

string s;
int ans = 1;
int k = 0, p = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'K') {
            if (p) p--;
            k++;
        }
        else {
            if (k) k--;
            p++;
        }
        ans = max(ans, max(k, p));
    }

    cout << ans;
}

