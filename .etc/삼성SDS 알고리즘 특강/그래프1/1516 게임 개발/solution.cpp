#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>
#define MAX 100000
#define LGN 17

using namespace std;

vector<int> adj[MAX + 1];
int visited[MAX + 1];
int depth[MAX + 1];
int parent[LGN + 1][MAX + 1];
queue<int> q;
int N, M;

void init() {
    memset(visited, 0, sizeof(visited));
    memset(depth, 0, sizeof(depth));
    for (int i = 1; i < N; i++) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
}

void bfs(int v) {
    while (!q.empty()) q.pop(); // 초기화

    q.push(v);
    // depth[v] = 0;
    visited[v] = 1;
    while(!q. empty()) {
        int now = q.front(); q.pop();
        for (auto next : adj[now]) {
            if (!visited[next]) {
                visited[next] = 1;
                depth[next] = depth[now] + 1;
                parent[0][next] = now;
                q.push(next);
            }
        }

    }
}

void aces_find() {
    for (int k = 1; k <= LGN; k++) {
        for (int v = 1; v <= N; v++) {
            parent[k][v] = parent[k - 1][parent[k - 1][v]];
        }
    }
}

int lca(int x, int y) {
    if (depth[x] > depth[y]) {
        int temp = x;
        x = y;
        y = temp;
    }

    // 높이 맞추기
    for (int i = LGN; i >= 0; i--) {
        if (depth[y] - depth[x] >= (1 << i)) {
            y = parent[i][y];
        }
    }

    if (x == y) return x;

    //  공통 조상 찾기
    for (int i = LGN; i >= 0; i--)  {
        if (parent[i][x] != parent[i][y]) {
            x = parent[i][x];
            y = parent[i][y];
        }
    }
    return parent[0][x];
}


// void print_parent() {
//     for (int i = 0; i < 2; i++) {
//         for (int j = 1; j <= N; j++) {
//             printf("%d ", parent[i][j]);
//         }
//         printf("\n");
//     }
// }

int main() {
    scanf("%d", &N);
    init();
    bfs(1);
    aces_find();
    // print_parent();
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", lca(x, y));
    }
}