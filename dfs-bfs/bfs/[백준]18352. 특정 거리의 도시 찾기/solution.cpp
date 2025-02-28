#include <bits/stdc++.h>
using namespace std;

int n, m, k, x, a, b;
vector<int> adj[300001];
vector<int> res;
int visited[300001];
queue<int> q;

void bfs(int s) {
    visited[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (auto &next: adj[now]) {
            if (visited[next]) continue;
            visited[next] = visited[now] + 1;
            if (visited[next] == k + 1) res.push_back(next);
            else q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    bfs(x);
    if (res.empty()) cout << -1;
    else {
        sort(res.begin(), res.end());
        for (auto &n: res)
            cout << n << '\n';
    }
}