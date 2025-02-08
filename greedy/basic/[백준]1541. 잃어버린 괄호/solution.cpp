#include <bits/stdc++.h>
using namespace std;

int res;
string s, n;
bool isMinus;

int main() {
    cin >> s;
    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == '+' || s[i] == '-') {
            if (isMinus) res -= stoi(n);
            else res += stoi(n);
            n = "";
        }
        else {
            n += s[i];
        }
        if (s[i] == '-') isMinus = true;
    }
    cout << res;   
}