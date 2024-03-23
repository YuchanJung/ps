#include<cstdio>
#include<algorithm>
#include<vector>
#include<string.h>
#define INF 987654321987654321
#define MAX_N 3000
using namespace std;
struct Node {
    int start;
    int end;
    int cost;
    Node(int start, int end, int cost) : start(start), end(end), cost(cost) {
    }
};

// 음수 오버플로우 주의 !!!
// 500 * 6000 * -10000 은 음수 오버플로우 날 수 있음
long long dist[MAX_N];
vector<Node> adjList;

// V : 정점의 수
// E : 간선의 수
// start : 시작 정점
bool BellmanFord(int V, int E, int start) {
    // 무한대 값으로 초기화
    for(int i = 1; i <= V; i++) {
        dist[i] = INF;
    }

    // 시작점은 거리 0 으로 세팅
    dist[start] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (Node node : adjList) {
            // 사이클의 유무만 파악하려면 dist[node.start] != INF 조건 삭제
            // 모든 정점들이 연결되어 있다는 보장이 없을 때
            // 다른 시작점에서 사이클이 발생할 수 있는 경우
            if (dist[node.start] == INF) continue;
            if (dist[node.end] > dist[node.start] + node.cost) {
                dist[node.end] = dist[node.start] + node.cost;
            }
        }
    }

    bool isNegativeCycle = false;

    for (Node node : adjList) {
        if (dist[node.start] == INF) continue;
        if (dist[node.end] > dist[node.start] + node.cost) {
            isNegativeCycle = true;
            break;
        }
    }

    return isNegativeCycle;

}

int main() {
    int N; // 정점의 수
    int M; // 도로의 수

    scanf("%d %d",&N, &M);
    memset(dist, 0, sizeof(dist));

    adjList.clear();

    for (int i = 0; i < M; i++) {
        int S, E, C;
        scanf("%d %d %d", &S, &E, &C);
        adjList.push_back(Node(S, E, C));
    }

    if (BellmanFord(N, M, 1)) {
        printf("-1\n");
    }
    else {
        for (int i = 2; i <= N; i++) {
            printf("%lld\n", dist[i] == INF ? -1 : dist[i]);
        }
    }

}