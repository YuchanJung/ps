#include <bits/stdc++.h>

using namespace std;

int n, r, q, a, b;
vector<int> adj[100001];
int visited[100001], cnt[100001];

void dfs(int root) {
    cnt[root] = 1;
    for (int i = 0; i < adj[root].size(); i++) {
        int next = adj[root][i];
        if (!visited[next]) {
            visited[next] = true;
            dfs(next);
            cnt[root] += cnt[next];
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited[r] = 1;
    dfs(r);
    while (q--) {
        cin >> a;
        cout << cnt[a] << '\n';
    }
}