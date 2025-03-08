#include <bits/stdc++.h>
using namespace std;

int n, m, k, a, b;
int parent[1000001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void _union(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px < py) parent[py] = px;
    else parent[px] = py;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) parent[i] = i;
    while (m--) {
        cin >> k >> a >> b;
        if (k) {
            if (find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
        else _union(a, b);
    }
}