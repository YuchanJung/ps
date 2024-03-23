#include <cstdio>
#include <vector>
#define INF 1000000000

using namespace std;

typedef long long ll;

struct Node {
    int dest;
    int cost;
    Node(int _dest, int _cost): dest(_dest), cost(_cost) {}
};

int n, m;
int a, b, c;
ll dist[501];
vector<Node> adj[501];

bool bf(int start) {
    dist[start] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto item: adj[j]) {
                if (dist[j] != INF && dist[item.dest] > dist[j] + item.cost) {
                    dist[item.dest] = dist[j] + item.cost;
                }
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        for (auto item: adj[j]) {
            if (dist[j] != INF && dist[item.dest] > dist[j] + item.cost) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(Node(b, c));
    }
    // init dist
    for (int i = 1; i <= 500; i++) dist[i] = INF;

    if (bf(1)) {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == INF) printf("-1\n");
            else printf("%d\n", dist[i]);
        }
    }
    else {
        printf("-1");
    }
}