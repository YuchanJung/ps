#include <bits/stdc++.h>

using namespace std;

string res;
string s1, s2;

int main() {
    cin >> s1 >> s2;
    int _s1 = s1.size(), _s2 = s2.size();
    for (int i = 0 ; i <= _s1; i++) {
        if (res.size() >= _s2) {
            bool flag = true;
            for (int j = 0; j < _s2; j++) {
                if (res[res.size() - _s2 + j] != s2[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.erase(res.size() - _s2, _s2);
        }
        if (i != _s1) res += s1[i];
    }
    if (res.size()) cout << res;
    else cout << "FRULA";
}