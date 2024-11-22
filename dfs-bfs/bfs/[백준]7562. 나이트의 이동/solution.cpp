#include <bits/stdc++.h>
using namespace std;
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dist[300][300];
int t, l, a, b, c, d;
queue<vector<int>> q;

int bfs() {
    dist[a][b] = 1;
    q.push({a, b});
    while (!q.empty()) {
        vector<int> v = q.front(); q.pop();
        int x = v[0], y = v[1];
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= l || ny >= l || dist[nx][ny]) continue;
            if (nx == c && ny == d) return dist[x][y];
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> l >> a >> b >> c >> d;
        cout << bfs() << '\n';
        memset(dist, 0, sizeof(dist));
        while (!q.empty()) q.pop();
    }
}