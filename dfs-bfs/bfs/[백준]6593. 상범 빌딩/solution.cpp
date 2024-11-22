#include <bits/stdc++.h>
using namespace std;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int l, r, c, ex, ey, ez;
int arr[30][30][30], dist[30][30][30];
string s;
queue<vector<int>> q;

void init() {
    memset(arr, 0, sizeof(arr));
    memset(dist, 0, sizeof(dist));
    while (!q.empty()) q.pop();
}

int bfs() {
    while (!q.empty()) {
        vector<int> v = q.front(); q.pop();
        int x = v[0], y = v[1], z = v[2];
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c) continue;
            if (!arr[nx][ny][nz] && !dist[nx][ny][nz]) {
                dist[nx][ny][nz] = dist[x][y][z] + 1;
                q.push({nx, ny, nz});
            }
        }
    }
    return dist[ex][ey][ez];
}

int main() {
    while (true) {
        init();
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) break;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                cin >> s;
                for (int k = 0; k < c; k++) {
                    if (s[k] == '#') arr[i][j][k] = 1;
                    if (s[k] == 'S') {
                        dist[i][j][k] = 1;
                        q.push({i, j, k});
                    }
                    if (s[k] == 'E') {
                        ex = i; ey = j; ez = k;
                    }
                }
            }
            cin.ignore();
            getline(cin, s);
        }
        int res = bfs();
        if (res) cout << "Escaped in " << res - 1 << " minute(s).\n";
        else cout << "Trapped!\n";
    }
}