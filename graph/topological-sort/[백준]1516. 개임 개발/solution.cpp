#include <bits/stdc++.h>
using namespace std;

int n, a;
int cost[501], degree[501], res[501];
vector<int> adj[501];
queue<int> q;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        while (1) {
            cin >> a;
            if (a == -1) break;
            adj[a].push_back(i);
            degree[i]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            res[i] = cost[i];
            q.push(i);
        }
    }
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (auto &next: adj[now]) {
            res[next] = max(res[next], res[now] + cost[next]);
            if (--degree[next] == 0) q.push(next);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << '\n';
}