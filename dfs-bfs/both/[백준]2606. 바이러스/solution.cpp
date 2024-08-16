#include <bits/stdc++.h>

using namespace std;

int n, m;
int a, b;
vector<int> adj[101];
bool visited[101] = {false};
int res = 0;

void dfs(int x) {
    for (int i = 0; i < adj[x].size(); i++) {
        int next = adj[x][i];
        if (!visited[next]) {
            visited[next] = true;
            res++;
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while(m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited[1] = 1;
    dfs(1);
    cout << res;
}