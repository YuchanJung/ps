#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool al[26];
char arr[20][20];
int dist[20][20];
int r, c, res = 1;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        int t = arr[nx][ny] - 65;
        if (al[t]) continue;
        al[t] = true;
        dist[nx][ny] = dist[x][y] + 1;
        res = max(res, dist[nx][ny]);
        dfs(nx, ny);
        al[t] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> arr[i][j];

    al[arr[0][0] - 65] = true;
    dist[0][0] = 1;
    dfs(0, 0);
    cout << res;
}