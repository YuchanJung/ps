#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
using ll = long long;

struct L {
    ll v;
    int idx;
    bool operator<(const L &n) const {
        return v > n.v;
    }
};
int n, l;
ll x;
priority_queue<L> pq;

int main() {
    fastio;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push({x, i});
        if (i >= l) {
            while (!pq.empty() && pq.top().idx <= i - l)
                pq.pop();
        }
        cout << pq.top().v << ' ';
    }
}