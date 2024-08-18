#include <bits/stdc++.h>
#define MAX 20000

using namespace std;

struct Node {
    int dest;
    int cost;
    Node(int d, int c): dest(d), cost(c) {};
    bool operator<(const Node &n) const {
        return cost > n.cost;
    }
};

int n, d, a, b, w;
set<int> node;
vector<Node> adj[MAX];
priority_queue<Node> pq;
int dist[MAX];
bool visited[MAX];

void dijkstra(int k) {
    for (int i = 0; i < MAX; i++) dist[i] = i;
    memset(visited, false, sizeof(visited));

    dist[k] = 0;
    pq.push(Node(k, 0));

    while (!pq.empty()) {
        Node now = pq.top(); pq.pop();
        if (visited[now.dest]) continue;

        visited[now.dest] = true;
        for (int i = 0; i < adj[now.dest].size(); i++) {
            Node next = adj[now.dest][i];
            if (dist[next.dest] >= dist[now.dest] + next.cost) {
                dist[next.dest] = dist[now.dest] + next.cost;
                pq.push(Node(next.dest, dist[next.dest]));
            }
        }
    }
}

int main() {
    cin >> n >> d;
    node.insert(0); node.insert(d);
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> w;
        adj[a].push_back(Node(b, w));
        for (auto &s: node) {
            if (s < a) adj[s].push_back(Node(a, a - s));
            if (s < b) adj[s].push_back(Node(b, b - s));

            if (s > a) adj[a].push_back(Node(s, s - a));
            if (s > b) adj[b].push_back(Node(s, s - b));
        }
        node.insert(a); node.insert(b);
    }

    dijkstra(0);
    cout << dist[d];
}