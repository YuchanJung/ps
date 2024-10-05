#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int n1, n2;
    int dist;
    Edge(int _n1, int _n2, int _dist): n1(_n1), n2(_n2), dist(_dist) {};
    bool operator<(const Edge &e) const {
        return dist < e.dist;
    }
};

int v, e;
int parent[10001];
vector<Edge> g;
int a, b, c, res;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); 
}

void _union(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px > py) parent[px] = py;
    else parent[py] = px;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> v >> e;
    for (int i = 1; i <=v; i++) parent[i] = i;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        g.push_back(Edge(a, b, c));
    }
    sort(g.begin(), g.end());

    for (int i = 0; i < e; i++) {
        Edge e = g[i];
        if (find(e.n1) != find(e.n2)) {
            res += e.dist;
            _union(e.n1, e.n2);
        }
    }
    cout << res;
}