#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, cnt, r;
vector<int> adj[10001], res;
bool visited[10001];

void dfs(int k) {
    for (auto &next: adj[k]) {
        if (visited[next]) continue;
        visited[next] = true;
        cnt++;
        dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        cnt = 1;
        visited[i] = true;
        dfs(i);
        if (cnt > r) {
            r = cnt;
            res.clear();
        }
        if (cnt == r) res.push_back(i);
    }
    sort(res.begin(), res.end());
    for (auto &n: res) cout << n << ' ';
}