#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int n1, n2, d;
    Edge(int _n1, int _n2, int _d): n1(_n1), n2(_n2), d(_d) {};
    bool operator<(const Edge& e) const {
        return d < e.d;
    }
};

int n, m;
int a, b, c;
int res, cnt;
int parent[100001];
vector<Edge> g;

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
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g.push_back(Edge(a, b, c));
    }
    sort(g.begin(), g.end());

    for (int i = 0; i < m; i++) {
        if (cnt >= n - 2) break;
        Edge e = g[i];
        if (find(e.n1) != find(e.n2)) {
            _union(e.n1, e.n2);
            res += e.d;
            cnt++;
        }
    }
    cout << res;
}