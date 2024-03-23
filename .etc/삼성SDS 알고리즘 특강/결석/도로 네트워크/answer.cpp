#include<cstdio>
#include<vector>
#include<string.h>
#include<queue>
#include<algorithm>

using namespace std;

#define MAX_N 100000
#define LGN 17

int parent[LGN+1][MAX_N+1];
int maxDist[LGN+1][MAX_N+1];
int minDist[LGN+1][MAX_N+1];
int depth[MAX_N+1];
bool visited[MAX_N+1];

int minAns, maxAns;

struct Node // priority queue에 넣을 상태 정보 
{
    int to; // 방문한 노드 
    int cost; // 노드까지의 거리 
    Node(int n, int c) {
        to = n;
        cost = c;
    }
};

vector<Node> adjList[MAX_N+1];

queue<int>q;
int N, Q;

int main() {

    scanf(" %d", &N);

    for (int i = 1; i <= N; i++) {
        adjList[i].clear();
        depth[i]=0;
        visited[i]=false;
        for (int j = 0; i <= LGN; i++) {
            parent[j][i]=0;

        }
    }

    for (int i = 1; i < N; i++) {
        int from, to, cost;
        scanf(" %d %d %d", &from, &to, &cost);
        adjList[from].push_back(Node(to, cost));
        adjList[to].push_back(Node(from, cost));
    }

    bfs(1, 0);
    aces_find();

    scanf(" %d", &Q);
    for (int i = 1; i <= Q; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        minAns = 987654321;
        maxAns = 0;
        lca(a, b);
        printf("%d %d\n", minAns,maxAns);
    }
}