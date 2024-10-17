// dfs & bfs, floyd-warshall
#include <bits/stdc++.h>

using namespace std;

int n;
int adj[100][100], res[100][100];
int visited[100];

void dfs(int now, int start) {
    for (int i = 0; i < n; i++) {
        int next = i;
        if (adj[now][next] && !visited[next]) {
            visited[next] = 1;
            res[start][next] = 1;
            dfs(next, start);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i, i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}