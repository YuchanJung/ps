#include <bits/stdc++.h>

using namespace std;

struct Loc {
    int x, y;
    int cost;
    Loc(int _x, int _y, int _c): x(_x), y(_y), cost(_c) {};
    bool operator<(const Loc& l) const {
        return cost > l.cost;
    }
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, cnt;
int arr[130][130], visited[130][130], dist[130][130];
priority_queue<Loc> pq;

void dijkstra(int x, int y) {
    dist[x][y] = arr[x][y];
    pq.push(Loc(x, y, dist[x][y]));
    
    while (!pq.empty()) {
        Loc now = pq.top(); pq.pop();
        if (visited[now.x][now.y]) continue;      
        visited[now.x][now.y] = 1;

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;
            if (dist[nx][ny] > dist[now.x][now.y] + arr[nx][ny]) {
                dist[nx][ny] = dist[now.x][now.y] + arr[nx][ny];
                pq.push(Loc(nx, ny, dist[nx][ny]));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    while (true) {
        cin >> n;
        if (n == 0) break;

        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                dist[i][j] = 999999;
            }
        }
        dijkstra(0, 0);
        cout << "Problem " << ++cnt << ": " << dist[n - 1][n - 1] << '\n';
    }
}