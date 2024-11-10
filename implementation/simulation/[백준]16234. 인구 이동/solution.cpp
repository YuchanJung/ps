#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N, L, R;
int arr[60][60];
int visited[60][60];
queue<vector<int>> q;

bool bfs(int x, int y) {
    int n = arr[x][y], c = 1;
    vector<vector<int>> v;
    v.push_back({x, y});

    visited[x][y] = 1;
    q.push({x, y});
    while (!q.empty()) {
        vector<int> now = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now[0] + dx[i];
            int ny = now[1] + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) continue;
            int d = abs(arr[nx][ny] - arr[now[0]][now[1]]);
            if (d >= L && d <= R) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
                n += arr[nx][ny];
                c++;
                v.push_back({nx, ny});
            }
        }
    }
    if (c > 1) {
        int p = n / c;
        for (auto &loc: v)
            arr[loc[0]][loc[1]] = p;
        return true;
    }
    return false;
}

int main() {
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    int cnt = 0;
    while (true) {
        memset(visited, 0, sizeof(visited));
        bool flag = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    bool move = bfs(i, j);
                    if (move) flag = true;
                }
            }
        }
        if (flag) cnt++;
        else break;
    }
    cout << cnt;
}