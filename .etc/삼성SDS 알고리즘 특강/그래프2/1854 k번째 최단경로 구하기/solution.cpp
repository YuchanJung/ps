#include <cstring>
#include <string.h>
#include <vector>
#include <queue>
#define INF 2000000000

using namespace std;

struct Node {
    int dest;
    int cost;
    Node(int _dest, int _cost): dest(_dest), cost(_cost) {}
    bool operator<(const Node &n) const {
        return cost > n.cost;
    }
};

int n, m, k;
int a, b, c;
int visited[1001];
int dist[101][1001] = {0};
vector<Node> adj[1001];
priority_queue<Node> pq;

void init() {
    memset(dist, 0, sizeof(dist));
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(Node(b, c));
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j<= n; j++) dist[i][j] = INF;
    }
}

void dijkstra(int k) {
    while (!pq.empty()) pq.pop();
    // start node is 1
    for (int i = 1; i <= k; i++) {
        // init visited
        memset(visited, 0, sizeof(visited));
        // dijkstra
        pq.push(Node(1, 0));
        dist[i][1] = 0;
        while (!pq.empty()) {
            Node now = pq.top(); pq.pop();
            if (visited[now.dest]) continue;

            if (now.cost > dist[i - 1][now.dest]) {
                // printf("visited %d with cost %d\n", now.dest, now.cost);
                visited[now.dest] = 1;
            }
            
            for (auto item: adj[now.dest]) {
                int w = dist[i][now.dest] + item.cost; 
                if (dist[i][item.dest] > w) {
                    if (w > dist[i - 1][item.dest]) {
                        // printf("dijkstra %d update %d with cost %d\n", i, item.dest, w);
                        dist[i][item.dest] = w;
                    }
                    // printf("dijkstra %d push %d with cost %d\n", i, item.dest, w);
                    pq.push(Node(item.dest, w));
                }
            }
        }
    }
}

void print_result() {
    for (int i = 1; i <= n; i++) {
        printf("%d\n", dist[2][i]);
    }
}

int main() {
    init();
    dijkstra(k);
    print_result();
}