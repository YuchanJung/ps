#include <bits/stdc++.h>
using namespace std;

struct Node {
    int dest, cost;
    bool operator<(const Node &n) const {
        return cost > n.cost;
    }
};
int t, n, d, c, a, b, s;
vector<Node> adj[10001];
int dist[10001], visited[10001];
priority_queue<Node> pq;
int cnt, res;

void dijkstra(int c) {
    dist[c] = 0;
    pq.push({c, 0});
    while (!pq.empty()) {
        Node now = pq.top(); pq.pop();
        if (visited[now.dest]) continue;

        visited[now.dest] = 1;
        cnt++;
        res = max(res, now.cost);
        for (auto &next: adj[now.dest]) {
            if (dist[next.dest] > dist[now.dest] + next.cost) {
                dist[next.dest] = dist[now.dest] + next.cost;
                pq.push({next.dest, dist[next.dest]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cnt = res = 0;
        while (!pq.empty()) pq.pop();
        memset(visited, 0, sizeof(visited));
        for (auto &v: adj) v.clear();
        for (auto &d: dist) d = 1000000000;
        
        cin >> n >> d >> c;
        for (int i = 0; i < d; i++) {
            cin >> a >> b >> s;
            adj[b].push_back({a, s});
        }    
        dijkstra(c);
        cout << cnt << ' ' << res << '\n';
    }
}