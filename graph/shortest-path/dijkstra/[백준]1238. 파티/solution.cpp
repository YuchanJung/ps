#include <bits/stdc++.h>
#define INF 999999999

using namespace std;

struct Node {
    int dest;
    int cost;
    Node(int d, int c): dest(d), cost(c) {}
    bool operator<(const Node& n) const {
        return cost > n.cost;
    }
};

int n, m, x;
int visited[1001];
vector<Node> adj[1001];
priority_queue<Node> pq;
int a, b, t;
int dist[1001], distToGo[1001];
int res;

void init() {
    memset(visited, 0, sizeof(visited));
    while (!pq.empty()) pq.pop();
    for (int i = 1; i <= n; i++) dist[i] = INF;
}

void dijkstra(int k) {
    dist[k] = 0;
    pq.push(Node(k, 0));
    while (!pq.empty()) {
        Node now = pq.top(); pq.pop();
        if (visited[now.dest]) continue;
        visited[now.dest] = 1;
        for (int i = 0; i < adj[now.dest].size(); i++) {
            Node next = adj[now.dest][i];

            if (dist[next.dest] > dist[now.dest] + next.cost) {
                dist[next.dest] = dist[now.dest] + next.cost;
                pq.push(Node(next.dest, dist[next.dest]));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        adj[a].push_back(Node(b, t));
    }
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        init();
        dijkstra(i);
        distToGo[i] = dist[x];
    }
    init();
    dijkstra(x);
    for (int i = 1; i <= n; i++) {
        if (distToGo[i] + dist[i] > res)
            res = distToGo[i] + dist[i];
    }
    cout << res;
}