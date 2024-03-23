#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>
#define INF 100000000

using namespace std;

struct Node {
    int dest;
    int cost;

    Node(int _dest, int _cost): dest(_dest), cost(_cost) {}
    bool operator<(const Node &n) const {
        return cost > n.cost;
    }
};

int n, m;
int prev_node[1001];
int visited[1001];
int dist[1001];
int to, from, weight;
vector<Node> adj[1001];
priority_queue<Node> pq;
vector<int> path;

void init() {
    memset(prev_node, 0, sizeof(prev_node));
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= 1000; i++) dist[i] = INF;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &to, &from, &weight);
        adj[to].push_back(Node(from, weight));
    }
    scanf("%d %d", &to, &from);
}

void dijkstra(int k) {
    pq.push(Node(k, 0));
    dist[k] = 0;
    while(!pq.empty()) {
        Node now = pq.top(); pq.pop();
        if (visited[now.dest]) continue;
        
        visited[now.dest] = 1;
        for (auto next: adj[now.dest]) {
            if (dist[next.dest] > dist[now.dest] + next.cost) {
                dist[next.dest] = dist[now.dest] + next.cost;
                pq.push(Node(next.dest, dist[next.dest]));
                prev_node[next.dest] = now.dest;
            }
        }
        
    }
}

void print_result() {
    int cnt = 1;
    printf("%d\n", dist[from]);
    path.push_back(from);
    while (prev_node[from] != 0) {
        path.push_back(prev_node[from]);
        from = prev_node[from];
        cnt++;
    }
    printf("%d\n",cnt);
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
}

int main() {
    init();
    dijkstra(to);
    print_result();
}