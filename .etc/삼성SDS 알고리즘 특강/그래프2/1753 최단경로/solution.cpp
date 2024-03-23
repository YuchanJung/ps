#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>
#define V_MAX 20000
#define E_MAX 300000
#define N_MAX 9999999

using namespace std;

struct Node {
    int dest;
    int cost;
    Node(int d, int c): dest(d), cost(c) {}
    bool operator<(const Node &n)const {
        return cost > n.cost;
    } 
};

int V, E, K;
int visited[V_MAX + 1];
int dist[V_MAX + 1];
vector<Node> adj[V_MAX + 1];
priority_queue<Node> pq;

void dijkstra(int K) {
    dist[K] = 0;
    pq.push(Node(K, 0));
    while(!pq.empty()) {
        Node now = pq.top(); pq.pop();

        if (visited[now.dest]) continue;

        visited[now.dest] = 1;

        for (auto next: adj[now.dest]) {
            if (dist[next.dest] > now.cost + next.cost) {
                dist[next.dest] = now.cost + next.cost;
                pq.push(Node(next.dest, dist[next.dest]));
            }
        }
    }
}

void init() {
    scanf("%d %d %d", &V, &E, &K);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(Node(v, w));
    }
    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= V; i++) {
        dist[i] = N_MAX;
    }
}

void print_dist() {
    for (int i = 1; i <= V; i++) {
        if (dist[i] == N_MAX) printf("INF\n");
        else printf("%d\n", dist[i]);
    }
}

int main() {
    init();
    dijkstra(K);
    print_dist();
}