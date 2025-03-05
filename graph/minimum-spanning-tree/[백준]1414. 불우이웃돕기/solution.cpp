#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, d;
    bool operator<(const Edge &e) const {
        return d < e.d;
    }
};
int n, res;
int parent[51];
vector<Edge> v;
string s;

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
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] >= 'a' && s[j] <= 'z') {
                v.push_back({i + 1, j + 1, s[j] - 96});
                res += s[j] - 96;
            }
            if (s[j] >= 'A' && s[j] <= 'Z') {
                v.push_back({i + 1, j + 1, s[j] - 38});
                res += s[j] - 38;
            } 
        }
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    for (auto &e: v) {
        if (find(e.a) != find(e.b)) {
            res -= e.d;
            _union(e.a, e.b);
            cnt++;
        }
    }
    if (cnt == n - 1) cout << res; 
    else cout << -1;
}