#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b;
    double c;
    bool operator<(const Edge &e) const {
        return c < e.c;
    }
};
int n;
int parent[100];
double res, a, b;
vector<vector<double>> coord;
vector<Edge> edges;

// double getDistance(double x1, double y1, double x2, double y2) {
//     return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
// }

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void _union(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px < py) parent[py] = px;
    else parent[px] = py;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        coord.push_back({a, b});
    }

    for (int i = 0; i < coord.size(); i++) {
        vector<double> v1 = coord[i];
        double x1 = v1[0], y1 = v1[1];
        for (int j = i + 1; j < coord.size(); j++) {
            vector<double> v2 = coord[j];
            double x2 = v2[0], y2 = v2[1];
            double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
            edges.push_back({i, j, d});
        }
    }

    for (int i = 0; i < n; i++) parent[i] = i;
    sort(edges.begin(), edges.end());
    for (auto &edge: edges) {
        if (find(edge.a) != find(edge.b)) {
            res += edge.c;
            _union(edge.a, edge.b);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << res;
}