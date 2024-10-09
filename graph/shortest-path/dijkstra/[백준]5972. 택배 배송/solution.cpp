#include <bits/stdc++.h>
#define MAX 60000
#define INF 100000000

using namespace std;

struct Node {
    int dest;
    int cost;
    Node(int d, int c): dest(d), cost(c) {}
    bool operator<(const Node& n) const {
        return cost > n.cost;
    }
};

int n, m, a, b, w;
bool visited[MAX];
int dist[MAX];
vector<Node> adj[MAX];
priority_queue<Node> pq;

void dijkstra(int k) {
    for (int i = 1; i <= n; i++) dist[i] = INF;

    dist[k] = 0;
    pq.push(Node(k, 0));

    while (!pq.empty()) {
        Node now = pq.top(); pq.pop();
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
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].push_back(Node(b, w));
        adj[b].push_back(Node(a, w));
    }
    
    dijkstra(1);
    cout << dist[n];
}