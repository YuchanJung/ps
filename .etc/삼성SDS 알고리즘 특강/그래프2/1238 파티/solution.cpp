#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>
#define V_MAX 1000
#define E_MAX 100000
#define N_MAX 100000000

using namespace std;

struct Node {
    int dest;
    int cost;
    // n c 잘못쳐서 오타남.. 그냥 _dest, _cost로 쓰자!
    Node(int n, int c): dest(n), cost(c) {}
    bool operator<(const Node &n) const{
        return dest > n.dest;
    }
};

int n, m, a, b;
int dist[V_MAX + 1];
int visited[V_MAX + 1];
int prevNode[V_MAX + 1];
vector<Node> adj[V_MAX + 1];
priority_queue<Node> pq;

void init() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(Node(v, w));
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        dist[i] = N_MAX;
    }
}

void dijkstra(int k) {
    dist[k] = 0;
    prevNode[k] = 0;
    pq.push(Node(k, 0));
    while (!pq.empty()) {
        Node now = pq.top(); pq.pop();

        if (visited[now.dest]) continue;

        visited[now.dest] = 1;

        for (auto next: adj[now.dest]) {
            if (dist[next.dest] > now.cost + next.cost) {
                dist[next.dest] = now.cost + next.cost;
                pq.push(Node(next.dest, dist[next.dest]));
                prevNode[next.dest] = now.dest;
            }
        }
    }
}

void print_path(int a, int b) {
    int sum = 1;
    vector<int> path;
    printf("%d\n", dist[b]);

    while (a != b) {
        path.push_back(b);
        b = prevNode[b];
        sum++;
    }
    path.push_back(a);
    printf("%d\n", sum);

    for (int i = sum - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
}

int main() {
    init();
    scanf("%d %d", &a, &b);
    dijkstra(a);
    print_path(a, b);
}
