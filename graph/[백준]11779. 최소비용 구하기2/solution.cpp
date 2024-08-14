#include <bits/stdc++.h>
#define MAX 999999999

using namespace std;

struct Node {
    int dest;
    int cost;
    Node(int d, int c): dest(d), cost(c) {}
    bool operator<(const Node &n) const {
        return cost > n.cost;
    }
};

int n, m, s, e, w, cnt;
bool visited[1001];
int dist[1001];
int parent[1001];
vector<Node> adj[1001];
priority_queue<Node> pq;
vector<int> path;


void init() {
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    for (int i = 1; i <= 1000; i++) dist[i] = MAX;
}

void dijkstra() {
    dist[s] = 0;
    pq.push(Node(s, 0));

    while (!pq.empty()) {
        Node now = pq.top(); pq.pop();
        if (visited[now.dest]) continue; // for문 안에 있을 경우 시간 초과
        visited[now.dest] = true;
        for (int i = 0; i < adj[now.dest].size(); i++) {
            Node next = adj[now.dest][i];
            if (dist[next.dest] > dist[now.dest] + next.cost) {
                dist[next.dest] = dist[now.dest] + next.cost;
                pq.push(Node(next.dest, dist[next.dest]));
                parent[next.dest] = now.dest;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    while (m--) {
        cin >> s >> e >> w;
        adj[s].push_back(Node(e, w));
    }
    cin >> s >> e;
    init();
    dijkstra();
    cout << dist[e] << '\n';
    // path
    while (e != 0) {
        path.push_back(e);
        e = parent[e];
        cnt++;
    }
    cout << cnt << '\n';
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << ' ';
    }
}