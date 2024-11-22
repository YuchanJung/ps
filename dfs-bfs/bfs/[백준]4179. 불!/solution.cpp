#include <bits/stdc++.h>
using namespace std;
using V = vector<int>;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int r, c;
int arr[1000][1000];
int dist[1000][1000];
deque<V> q;

int bfs() {
    while (!q.empty()) {
        V v = q.front(); q.pop_front();
        int x = v[0], y = v[1], k = v[2];
        if (!k && (x == 0 || x == r - 1 || y == 0 || y == c - 1))
            return dist[x][y];
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c || dist[nx][ny]) continue;
            if (arr[nx][ny] == 1) continue;
            if (!k) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push_back({nx, ny, 0});
            }
            else {
                arr[nx][ny] = 1;
                q.push_back({nx, ny, 1});
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> r >> c;
    string s;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == 'J') {
                dist[i][j] = 1;
                q.push_back({i, j, 0});
            }
            else if (s[j] == 'F') {
                arr[i][j] = 1;
                q.push_front({i, j, 1});
            }
            else if (s[j] == '#') {
                arr[i][j] = 1;
            }
        }
    }
    int res = bfs();
    if (res) cout << res;
    else cout << "IMPOSSIBLE";
}