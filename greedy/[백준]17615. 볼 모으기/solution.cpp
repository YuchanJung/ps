#include <bits/stdc++.h>

using namespace std;

vector<string> v;
int n, res = 999999;
int r, b;
string s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> s;
    string temp;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') r++;
        if (temp.size() == 0) {
            temp = s[i];
            continue;
        }
        if (temp.back() != s[i]) {
            v.push_back(temp);
            temp = s[i];
        }
        else {
            temp += s[i];
        }
    }
    b = n - r;
    v.push_back(temp);
    if (v.size() <= 2) {
        cout << 0;
        return 0;
    }
    int fs = v.front().size();
    int bs = v.back().size();
    if (v.front()[0] == 'R') res = min(res, min(r - fs, b));
    else res = min(res, min(r, b - fs));
    if (v.back()[0] == 'R') res = min(res, min(r - bs, b));
    else res = min(res, min(r, b - bs));
    cout << res;


    // for (int i = 0; i < v.size() - 1; i++) {
    //     if (v[i][0] == 'R') r += v[i].size();
    //     else b += v[i].size();
    // }
    // res = min(res, min(r, b));
    // if (v.front()[0] == 'R') r -= v.front().size();
    // else b -= v.front().size();
    // if (v.back()[0] == 'R') r += v.back().size();
    // else b += v.back().size();
    // res = min(res, min(r, b));
    // cout << res;
}
