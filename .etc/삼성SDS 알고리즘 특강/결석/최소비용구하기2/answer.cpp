#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

#define NMAX 1000
#define MMAX 100000

using namespace std;

int T, N, M, ans, cnt;

struct Node {
    int dest, cost;

    Node(int dest, int cost) : dest(dest), cost(cost) {}

    bool operator<(const Node& a) const {
        return a.cost < cost;
    }

};
vector<Node> adjList[NMAX+1];
int dist[NMAX+1];
int before[NMAX+1];
bool visited[NMAX+1];
queue<int> q;
stack<int> path;

void dijkstra(int start, int end) {
    priority_queue<Node> pq;
    pq.push(Node(start, 0));
    dist[start] = 0; // 처리해줘야함  

    while(!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        if (dist[now.dest] < now.cost) {
            continue;
        }

        if (now.dest == end){
            break;
    }

        for (Node next : adjList[now.dest]) {
            if (dist[next.dest] > now.cost + next.cost) {
                dist[next.dest] = now.cost + next.cost;
                pq.push(Node(next.dest, dist[next.dest]));
                before[next.dest] = now.dest;
            }
        }
    }

}

void getPath(int start, int end) {
    while(!path.empty()) path.pop();

    int idx = end;
    path.push(idx);
        cnt++;
    while (idx != start) {
        idx = before[idx];
        path.push(idx);
        cnt++;
    }
}

int main() {

    ans = 0;
    cnt = 0;

    scanf(" %d", &N);
    scanf(" %d", &M);

    // 초기화 
    for (int i=1; i<=N; i++) {
        adjList[i].clear();
        dist[i] = INT_MAX;
    }

    for (int i=1; i<=M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adjList[a].push_back(Node(b, c));
    }

    int S, E;
    scanf("%d %d", &S, &E);
    dijkstra(S, E);

    getPath(S, E);
    printf("%d\n", dist[E]);
    printf("%d\n", cnt);

    while(!path.empty()) {
        int a = path.top(); path.pop();
        printf("%d ", a);
    }
    printf("\n");
}