#include <cstdio>
#include <string.h>
#include <vector>
#define MAX 32000

using namespace std;

vector<int> adj[MAX + 1];
int visited[MAX + 1];
vector<int> res;
int N, M;
int a, b;

void dfs(int v) {
    visited[v] = 1;
    for (auto item: adj[v]) {
        if (!visited[item]) {
            dfs(item);
        }
    }
    res.push_back(v);
}

void topological_sort() {
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) dfs(i);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }

    topological_sort();

    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }
}