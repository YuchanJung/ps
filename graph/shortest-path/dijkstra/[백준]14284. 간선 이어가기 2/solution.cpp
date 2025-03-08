#include <bits/stdc++.h>
using namespace std;

struct Node {
    int dest, cost;
    bool operator<(const Node &n) const {
        return cost > n.cost;
    }
};
int n, m, a, b, c, s, t;
vector<Node> adj[5001];
priority_queue<Node> pq;
bool visited[5001];
int dist[5001];

void dijkstra(int s) {
    dist[s] = 0;
    pq.push({s, 0});
    
    while (!pq.empty()) {
        Node now = pq.top(); pq.pop();
        if (visited[now.dest]) continue;

        visited[now.dest] = true;
        for (auto &next: adj[now.dest]) {
            if (dist[next.dest] > dist[now.dest] + next.cost) {
                dist[next.dest] = dist[now.dest] + next.cost;
                pq.push({next.dest, dist[next.dest]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> s >> t;
    for (int i = 1; i <= n; i++) dist[i] = 999999999;
    dijkstra(s);
    cout << dist[t];
}