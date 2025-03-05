#include <bits/stdc++.h>
using namespace std;
using V = vector<int>;

struct Edge {
    int a, b, c;
    bool operator<(const Edge &e) const {
        return c < e.c;
    }
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, res;
int arr[10][10], visited[10][10];
int parent[11];
queue<V> q;
vector<V> v;
vector<Edge> edges;

void bfs(int r, int c, int k);
void makeEdge(int r, int c, int d);
void _union(int x, int y);
int find(int x);

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j]) v.push_back({i, j});
        }
    }
    // nodes
    int cnt = 0;
    for (auto &x: v) {
        int r = x[0], c = x[1];
        if (!arr[r][c] || visited[r][c]) continue;
        bfs(r, c, ++cnt);
    }
    // edges
    for (auto &x: v) {
        int r = x[0], c = x[1];
        if (!arr[r][c]) continue;
        for (int d = 0; d < 4; d++)
            makeEdge(r, c, d);
    }
    // mst
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= 10; i++)
        parent[i] = i;

	for (auto &e: edges) {
		if (find(e.a) != find(e.b)) {
			res += e.c;
			_union(e.a, e.b);
		}
	}

	int p = find(1);
	for (int i = 2; i <= cnt; i++)
		if (p != find(i))
			res = -1;

    cout << res;
}

void bfs(int r, int c, int k) {
    arr[r][c] = k;
    visited[r][c] = 1;
    q.push({r, c});
    while (!q.empty()) {
        V now = q.front(); q.pop();
        int x = now[0], y = now[1];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) continue;
            if (arr[nx][ny] == 0) continue;
            arr[nx][ny] = k;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

void makeEdge(int r, int c, int d) {
    int l = 0;
    int k = arr[r][c];
    int nx = r, ny = c;
    while (true) {
        nx += dx[d];
        ny += dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == k) return;
        if (arr[nx][ny] == 0) l++;
        else {
            if (l >= 2) edges.push_back({k, arr[nx][ny], l});
            return;
        }
    }
} 

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); 
}

void _union(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px > py) parent[px] = py;
    else parent[py] = px;
}