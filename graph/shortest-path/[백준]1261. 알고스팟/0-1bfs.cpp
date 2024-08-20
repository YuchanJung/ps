// 0-1 bfs
#include <bits/stdc++.h>
#define MAX 99999

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int arr[100][100];
int dist[100][100];
deque<vector<int>> d;
int n, m;

void bfs() {
    while (!d.empty()) {
        vector<int> v = d.front(); d.pop_front();
        int x = v[0], y = v[1];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] != 0) continue;
            if (arr[nx][ny] == 1) {
                dist[nx][ny] = dist[x][y] + 1;
                d.push_back({nx, ny});
            } else {
                dist[nx][ny] = dist[x][y];
                d.push_front({nx, ny});
            }
        }
    }
}

int main() {
    cin >> m >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    d.push_back({0, 0});
    dist[0][0] = 1;
    bfs();
    cout << dist[n - 1][m - 1] - 1;
}