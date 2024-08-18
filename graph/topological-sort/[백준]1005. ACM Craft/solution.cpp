#include <bits/stdc++.h>

using namespace std;

int T, N, K, W;
int x, y;
int arr[1001];
int res[1001];
int degree[1001];
vector<int> adj[1001];
queue<int> q;

void bfs() {
    for (int i = 1; i <= N; i++) {
        if (!degree[i]) {
            res[i] = arr[i];
            q.push(i);
        }
    }
    while(!q.empty()) {
        int n = q.front(); q.pop();
        for (auto next: adj[n]) {
            res[next] = max(res[next], res[n] + arr[next]);
            if (--degree[next] == 0) q.push(next);
        }
    }
}

void init() {
    memset(arr, 0, sizeof(arr));
    memset(res, 0, sizeof(res));
    memset(res, 0, sizeof(degree));
    for (int i = 0; i < 1001; i++) adj[i].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        init();
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];
        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            degree[y]++;
        }
        bfs();
        cin >> W;
        cout << res[W] << '\n';
    }
}