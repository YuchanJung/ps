#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, k, res;
priority_queue<ll> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> k;
        pq.push(-k);
    }
    for (int i = 0; i < m; i++) {
        ll x = -pq.top(); pq.pop();
        ll y = -pq.top(); pq.pop();
        pq.push(-(x + y));
        pq.push(-(x + y));
    }
    while (!pq.empty()) {
        res += -pq.top(); pq.pop();
    }
    cout << res;
}