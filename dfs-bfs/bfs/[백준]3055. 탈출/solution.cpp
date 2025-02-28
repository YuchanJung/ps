#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int r, c;
int matrix[50][50];
int dist[50][50];
deque<vector<int>> dq;

int bfs() {
    while (!dq.empty()) {
        vector<int> now = dq.front(); dq.pop_front();
        int x = now[0], y = now[1], k = now[2];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (matrix[nx][ny] == 1) continue;
            if (k && matrix[nx][ny] != 2) {
                matrix[nx][ny] = 1;
                dq.push_back({nx, ny, 1});
            }
            if (!k && !dist[nx][ny]) {
                if (matrix[nx][ny] == 2) return dist[x][y];
                dist[nx][ny] = dist[x][y] + 1;
                dq.push_back({nx, ny, 0});
            }
        }
    }
    return 0;
}

int main() {
    cin >> r >> c;
    string s;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == 'D') {
                matrix[i][j] = 2;
            }
            if (s[j] == '*') {
                matrix[i][j] = 1;
                dq.push_front({i, j, 1});
            }
            if (s[j] == 'X') {
                matrix[i][j] = 1;
            }
            if (s[j] == 'S') {
                dist[i][j] = 1;
                dq.push_back({i, j, 0});
            }
        }
    }
    int res = bfs();
    if (res) cout << res;
    else cout << "KAKTUS";
}