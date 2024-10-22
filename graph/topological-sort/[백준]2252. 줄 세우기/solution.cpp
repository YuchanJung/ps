#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
vector<int> adj[32001];
int degree[32001];
queue<int> q;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        degree[b]++;
    }

    for (int i = 1; i <= n; i++)
        if (!degree[i])
            q.push(i);

    while (!q.empty()) {
        int now = q.front(); q.pop();
        cout << now << ' ';
        for (int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i];
            if (--degree[next] == 0)
                q.push(next);
        }
    }
}