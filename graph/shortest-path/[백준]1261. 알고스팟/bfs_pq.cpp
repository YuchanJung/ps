#include <bits/stdc++.h>

using namespace std;

// struct Pos {
//     int x, y, d;
//     Pos(int _x, int _y, int _d): x(_x), y(_y), d(_d) {};
//     bool operator<(const Pos &p) const{
//         return d > p.d;
//     }
// };

typedef tuple<int, int, int> P;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;
int arr[100][100];
int dist[100][100];
int visited[100][100];
priority_queue<P, vector<P>, greater<P>> pq;

void bfs() {
    pq.push(make_tuple(1, 0, 0));
    while (!pq.empty()) {
        int d, x, y;
        tie(d, x, y) = pq.top();
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[nx][ny] <= d || visited[nx][ny]) continue;
            if (arr[nx][ny] == 0) {
                dist[nx][ny] = d;
            }
            else {
                dist[nx][ny] = d + 1;
            }
            visited[nx][ny] = 1;
            pq.push({dist[nx][ny], nx, ny});
        }
    }
}

int main() {
    string s;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
            dist[i][j] = 99999;
        }
    }
    dist[0][0] = visited[0][0] = 1;
    bfs();
    cout << dist[n - 1][m - 1] - 1;
}