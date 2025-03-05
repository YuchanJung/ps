#include <bits/stdc++.h>
#define INF 999999999

using namespace std;

struct Node {
    int dest, cost;
};
int n, m;
int a, b, c;
long long dist[501];
vector<Node> adj[501];

bool bellamford(int s) {
    dist[s] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto &item: adj[j]) {
                if (dist[j] != INF && dist[item.dest] > dist[j] + item.cost) {
                    dist[item.dest] = dist[j] + item.cost;
                    if (i == n) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    for (int i = 1; i <= 500; i++) dist[i] = INF;

    if (bellamford(1)) {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }
    else cout << -1;
}