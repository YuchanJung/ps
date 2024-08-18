#include <bits/stdc++.h>
#define INF 999999999

using namespace std;

struct Node {
    int dest;
    int cost;
    Node(int d, int c): dest(d), cost(c) {}
    bool operator<(const Node &n) const{
        return cost > n.cost;
    }
};

int n, m;
int a, b, w;
vector<Node> adj[1001];
priority_queue<Node> pq;
int dist[1001];
bool visited[1001];

void init() {
    memset(visited, false, sizeof(visited));
    for (int i = 1; i < 1001; i++) dist[i] = INF;
}

void dijkstra(int k) {
    dist[k] = 0;
    pq.push(Node(k, 0));
    while (!pq.empty()) {
        Node now = pq.top(); pq.pop();
        if (visited[now.dest]) continue;
        visited[now.dest] = true;
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].push_back(Node(b, w));
    }
    cin >> a >> b;
    init();
    dijkstra(a);
    cout << dist[b];
}