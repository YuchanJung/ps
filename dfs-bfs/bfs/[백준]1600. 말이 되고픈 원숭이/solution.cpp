#include <bits/stdc++.h>
using namespace std;
using V = vector<int>;

int dx[12] = {1, -1, 0, 0, -1, -2, -2, -1, 1, 2, 2, 1};
int dy[12] = {0, 0, 1, -1, -2, -1, 1, 2, 2, 1, -1, -2};
int k, w, h, res = 999999;
int arr[200][200];
int dist[200][200][31];
queue<V> q;

void bfs(int x, int y) {
    dist[x][y][0] = 1;
    q.push({x, y, 0});
    while (!q.empty()) {
        V now = q.front(); q.pop();
        int x = now[0], y = now[1], z = now[2];
        int nx, ny, nz;
        for (int i = 0; i < 12; i++) {
            if (i > 3 && z == k) break;
            nx = x + dx[i];
            ny = y + dy[i];
            nz = i > 3 ? z + 1 : z;
            if (nx < 0 || ny < 0|| nx >= h || ny >= w || dist[nx][ny][nz]) continue;
            if (arr[nx][ny]) continue;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            q.push({nx, ny, nz});
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> arr[i][j];
        }
    }
    bfs(0, 0);
    for (int i = 0; i <= k; i++) {
        if (dist[h - 1][w - 1][i] != 0)
            res = min(res, dist[h - 1][w - 1][i] - 1);
    }
    if (res == 999999) cout << -1;
    else cout << res;
}