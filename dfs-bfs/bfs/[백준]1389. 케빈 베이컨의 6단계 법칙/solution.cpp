// bfs, 최단경로, 플로이드 워셜
#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
int dist[101];
vector<int> adj[101];
queue<int> q;
int idx, bm = 9999999;

int bfs(int start) {
    int cnt = 0;
    q.push(start);
    dist[start] = 1;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i];
            if (dist[next]) continue;
            dist[next] = dist[now] + 1;
            cnt += dist[next] - 1;
            q.push(next);
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        memset(dist, 0, sizeof(dist));
        int bacon = bfs(i);
        if (bm > bacon) {
            bm = bacon;
            idx = i;
        }
    }
    cout << idx;
}