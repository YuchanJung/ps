#include <bits/stdc++.h>
using namespace std;

int k, v, e, a, b;
vector<int> adj[20001];
int visited[20001];
queue<int> q;

bool bfs(int s) {
    visited[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        int b = visited[now];
        for (auto &next: adj[now]) {
            if (!visited[next]) {
                visited[next] = b ^ 3;
                q.push(next);
            }
            else if (visited[next] == b) {
                return false;
            }
        }
    }
    return true;
}

// bool dfs(int s, int b) {
//     for (auto &next: adj[s]) {
//         if (visited[next] && b == visited[next]) {
//             return false;
//         }
//         if (!visited[next]) {
//             visited[next] = b ^ 3;
//             bool flag = dfs(next, visited[next]);
//             if (!flag) return false;
//         }
//     }
//     return true;
// }

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> k;
    while (k--) {
        for (auto &n: adj) n.clear();
        memset(visited, 0, sizeof(visited));
        while (!q.empty()) q.pop();
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool isBipartite = true;
        for (int i = 1; i <= v; i++) {
            if (visited[i]) continue;
            isBipartite = bfs(i);
            if (!isBipartite) break;
        }
        if (isBipartite) cout << "YES\n";
        else cout << "NO\n";
    }    
}