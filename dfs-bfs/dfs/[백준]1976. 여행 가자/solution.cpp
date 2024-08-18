#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[210][210], go[210][210];
int visited[210];
int p[1100];

void dfs(int x, int k) {
    for (int i = 1; i <= n; i++) {
        if (x == i) continue;
        if (arr[x][i] == 1 && !visited[i]) {
            visited[i] = 1;
            go[k][i] = 1;
            dfs(i, k);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++) cin >> p[i];

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        go[i][i] = 1;
        dfs(i, i);
    }

    int start = p[0];
    bool flag = true;
    for (int i = 1; i < m; i++) {
        if (!go[start][p[i]]) {
            flag = false;
            break;
        }
        start = p[i];
    }
    if (flag) cout << "YES";
    else cout << "NO";
}