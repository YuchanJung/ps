#include <iostream>
#include <queue>
#include <vector>
#define MAX 999999

using namespace std;

struct Node {
    int x;
    int y;
    Node(int _x, int _y): x(_x), y(_y) {}
};

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int N;
int arr[20][20], dist[20][20];
int shark_size = 2, res, eat;
Node shark(0, 0);
queue<Node> q;

void init() {
    while(!q.empty()) q.pop();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) dist[i][j] = 0;
    }
}

int bfs(int sx, int sy) {
    int min_dist = MAX;
    init();
    dist[sx][sy] = 1;
    q.push(Node(sx, sy));
    while(!q.empty()) {
        Node now = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (arr[nx][ny] > shark_size) continue;
            if (dist[nx][ny] == 0) {
                dist[nx][ny] = dist[now.x][now.y] + 1;
                if (0 < arr[nx][ny] && arr[nx][ny] < shark_size) {
                    if (min_dist == MAX) {
                        min_dist = dist[nx][ny];
                        shark.x = nx;
                        shark.y = ny;
                    }
                    else if (dist[nx][ny] == min_dist) {
                        if (nx < shark.x || (nx == shark.x && ny < shark.y)) {
                            shark.x = nx;
                            shark.y = ny;
                        }
                    }
                }
                q.push(Node(nx, ny));
            }
        }
    }
    if (sx == shark.x && sy == shark.y) return 0;
    else {
        eat++;
        arr[shark.x][shark.y] = 0;
        if (shark_size == eat) {
            shark_size++;
            eat = 0;
        }
        res += dist[shark.x][shark.y] - 1;
        return 1;
    } 
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                shark.x = i;
                shark.y = j;
                arr[i][j] = 0;
            }
        }
    }
    while (bfs(shark.x, shark.y));
    cout << res;
}