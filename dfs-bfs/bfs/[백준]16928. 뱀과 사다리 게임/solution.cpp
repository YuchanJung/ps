#include <bits/stdc++.h>

using namespace std;

int N, M, u, v;
int dist[101], jump[101];
queue<int> q;

void bfs() {
    dist[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int i = 1; i <= 6; i++) {
            int next = now + i;
            if (next > 100 || dist[next]) continue;
            
            dist[next] = dist[now] + 1;
            int j = jump[next];
            if (j) {
                if (!dist[j]) {
                    dist[j] = dist[next];
                    q.push(j);
                }  
            }
            else q.push(next);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N + M; i++) {
        cin >> u >> v;
        jump[u] = v;
    }
    bfs();
    cout << dist[100] - 1;
}