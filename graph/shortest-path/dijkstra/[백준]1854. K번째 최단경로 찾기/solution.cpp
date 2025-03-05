#include <bits/stdc++.h>
using namespace std;

struct Node{
    int dest, cost;
    bool operator<(const Node& n) const {
        return cost > n.cost;
    }
};
int n, m, k, a, b, c;
vector<Node> adj[1001];
priority_queue<Node> pq;
priority_queue<int> res[1001];

void kth_dijkstra(int c) {
    pq.push({c, 0});
    res[c].push(0);

    while (!pq.empty()) {
        Node now = pq.top(); pq.pop();

        for (auto& next: adj[now.dest]) {
            int nd = next.dest;
            int nc = next.cost;
            if (res[nd].size() < k || res[nd].top() > now.cost + nc) {
                if (res[nd].size() == k) res[nd].pop();
                res[nd].push(now.cost + nc);
                pq.push({nd, now.cost + nc});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        
        adj[a].push_back({b, c});
    }
    kth_dijkstra(1);
    for (int i = 1; i <= n; i++) {
        if (res[i].size() < k) cout << "-1\n";
        else cout << res[i].top() << "\n";
    }
}