#include <bits/stdc++.h>

using namespace std;

int n, m, v, x, y;
vector<int> adj[1001];
queue<int> q;
bool visited[1001];

void bfs(int k) {
    q.push(k);
    visited[k] = true;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i];
            if (!visited[next]) {
                visited[next] = true;
                cout << next << ' ';
                q.push(next);
            } 
        }
    }
}

void dfs(int k) {
    for (int i = 0; i < adj[k].size(); i++) {
        int next = adj[k][i];
        if (!visited[next]) {
            visited[next] = true;
            cout << next << ' ';
            dfs(next);
        }
    }
}

int main() {
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        sort(adj[x].begin(), adj[x].end());
        sort(adj[y].begin(), adj[y].end());
    }
    cout << v << ' ';
    visited[v] = true;
    dfs(v); 
    memset(visited, false, sizeof(visited));
    cout << '\n' << v << ' '; 
    bfs(v);
}
