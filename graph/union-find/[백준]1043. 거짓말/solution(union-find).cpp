#include <bits/stdc++.h>

using namespace std;

int n, m, k, x, res;
int h[51], parent[51];
vector<int> p[50];

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void _union(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa > pb) parent[pa] = pb;
    else parent[pb] = pa;
}

int main() {
    cin >> n >> m;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x;
        h[x] = 1;
    }
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> x;
            int temp;
            if (j == 0) temp = x;
            if (j > 0) _union(temp, x);
            p[i].push_back(x);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (h[i] == 0) continue;
        for (int j = 1; j <= n; j++) {
            if (find(i) == find(j)) h[j] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        bool flag = true;
        for (auto &s: p[i]) {
            if (h[s]) flag = false;
        }
        if (flag) res++;
    }
    cout << res;
}