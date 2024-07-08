#include <bits/stdc++.h>

using namespace std;

int n, m;
unordered_map<string, int> mp;
string s;

static bool comp(pair<string, int> &a, pair<string, int> &b) {
    if (a.second == b.second) {
        if (a.first.length() == b.first.length()) 
           return a.first < b.first;
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    while (n--) {
        cin >> s;
        if (s.length() < m) continue;
        if (mp.find(s) == mp.end()) 
            mp.insert({s, 1});
        else {
            mp[s] += 1;
        }
    }
    vector<pair<string, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), comp);
    for (auto &i: v)
        cout << i.first << '\n';
}