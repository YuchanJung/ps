#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, l, x;
deque<vector<ll>> dq;
string ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!dq.empty() && dq.front()[1] <= i - l) dq.pop_front();
        while (!dq.empty() && dq.back()[0] > x) dq.pop_back();
        // if (!dq.empty()) {
        //     if (dq.front()[1] <= i - l) dq.pop_front();
        //     while (!dq.empty() && dq.back()[0] > x) dq.pop_back();
        // }
        dq.push_back({x, i});
        ans += to_string(dq.front()[0]) + " ";
    }
    cout << ans;
}