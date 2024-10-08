#include <bits/stdc++.h>

using namespace std;

struct Pos {
    int x, y, h, d;
    Pos(int _x, int _y, int _h, int _d): x(_x), y(_y), h(_h), d(_d) {}
    bool operator<(const Pos &p) const {
        return h < p.h;
    }
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int m, n;
int arr[500][500];
int dp[500][500];
priority_queue<Pos> pq;

void bfs() {
    while(!pq.empty()) {
        Pos p = pq.top(); pq.pop();
        int x = p.x, y = p.y, h = p.h, d = p.d;
        if (d != dp[x][y]) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (arr[nx][ny] < arr[x][y]) {
                dp[nx][ny] += dp[x][y];
                pq.push({nx, ny, arr[nx][ny], dp[nx][ny]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    dp[0][0] = 1;
    pq.push({0, 0, arr[0][0], 1});
    bfs();
    cout << dp[m - 1][n - 1];
}
