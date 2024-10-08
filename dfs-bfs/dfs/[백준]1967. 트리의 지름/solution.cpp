#include <bits/stdc++.h>

using namespace std;

struct Node {
    int n, w;
    Node(int _n, int _w): n(_n), w(_w) {};
};

int n;
int a, b, c, l, e;
vector<Node> adj[10001];
int visited[10001];

void init(int s) {
    l = 0;
    memset(visited, 0, sizeof(visited));
    visited[s] = 1;
}

void dfs(int n, int k) {
    if (l < k) {
        l = k;
        e = n;
    }
    for (int i = 0; i < adj[n].size(); i++) {
        Node next = adj[n][i];
        if (!visited[next.n]) {
            visited[next.n] = 1;
            dfs(next.n, k + next.w);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n -1; i++) {
        cin >> a >> b >> c;
        adj[a].push_back(Node(b, c));
        adj[b].push_back(Node(a, c));
    }
    init(1);
    dfs(1, 0);
    init(e);
    dfs(e, 0);
    cout << l;
}