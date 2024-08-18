#include <bits/stdc++.h>
#define INF 99999999

using namespace std;

struct Node {
    int dest;
    int cost;
    Node(int _dest, int _cost):dest(_dest), cost(_cost) {}
    bool operator<(const Node &n) const{
        return cost > n.cost;
    }
};

int v, e;
int start, from, to, w;
priority_queue<Node> pq;
vector<Node> adj[20001];
int dist[20001];
bool visited[20001];

void dijkstra(int k) {
    dist[k] = 0;
    pq.push(Node(k, 0)); 

    while(!pq.empty()) {
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
    cin >> v >> e >> start;
    for (int i = 0; i < e; i++) {
        cin >> from >> to >> w;
        adj[from].push_back(Node(to, w));
    }

    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= v; i++) dist[i] = INF;

    dijkstra(start);

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}