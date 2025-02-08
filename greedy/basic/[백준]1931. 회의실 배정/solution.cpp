#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int n, a, b, cnt, k;
vector<P> v;

bool comp(P &a, P &b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; i++) {
        if (v[i].first >= k) {
            cnt++;
            k = v[i].second;
        }
    }
    cout << cnt;
}