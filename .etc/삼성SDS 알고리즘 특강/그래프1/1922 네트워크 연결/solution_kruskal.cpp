#include <cstdio>
#include <queue>

using namespace std;

struct edge {
    int from;
    int to;
    int cost;

    edge(int f, int t, int c) : from(f), to(t), cost(c) {};

    bool operator<(const edge& e) const {
        return cost > e.cost;
    }
};

int N, M;
int parent[1001];
int visited[1001];
priority_queue<edge> pq;


int getParent(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = getParent(parent[a]);
}

void _union(int a, int b) {
    int x = getParent(a);
    int y = getParent(b);
    if (x < y) parent[y] = parent[x];
    else parent[x] = parent[y];
}

bool find(int a, int b) {
    int x = getParent(a);
    int y = getParent(b);
    return x == y;
}

int make_MST() {
    int sum = 0;
    int selecetd = 0;
    while(!pq.empty()) {
        edge e = pq.top(); pq.pop();
        if (!find(e.from, e.to)) {
            _union(e.from, e.to);
            sum += e.cost;
            selecetd++;
        }
        if (selecetd == N - 1) break;
    }
    return sum;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        pq.push(edge(from, to, cost));
    }

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    printf("%d", make_MST());
}