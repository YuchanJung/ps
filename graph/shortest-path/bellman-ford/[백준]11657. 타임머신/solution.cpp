#include <bits/stdc++.h>
#define INF 999999999

using namespace std;

struct Node {
    int dest;
    int cost;
    Node (int _d, int _c): dest(_d), cost(_c) {};
};

int n, m;
int a, b, c;
long long dist[501];
vector<Node> adj[501];

bool bf(int s) {
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto &item: adj[j]) {
                if (dist[j] != INF && dist[item.dest] > dist[j] + item.cost) {
                    dist[item.dest] = dist[j] + item.cost;
                }
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        for (auto &item: adj[j]) {
            if (dist[j] != INF && dist[item.dest] > dist[j] + item.cost) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back(Node(b, c));
    }

    for (int i = 1; i <= 500; i++) dist[i] = INF;

    if (bf(1)) {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == INF) cout << -1;
            else cout << dist[i];
            cout << '\n';
        }
    }
    else {
        cout << -1;
    }
}