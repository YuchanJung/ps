#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, res;
int parent[500000];

int find (int x) {
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
    for (int i = 0; i < n; i++) parent[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        if (find(a) == find(b)) {
            res = i;
            break;
        }
        _union(a, b);
    }
    cout << res;
}