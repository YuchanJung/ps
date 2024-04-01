#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int m[3] = {-1, 1, 2};

int arr[MAX + 1] = {0};
int prev_node[MAX + 1] = {0};
int n, k;
queue<int> q;
vector<int> path;

void bfs() {
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for (int i = 0; i < 3; i++) {
            int next = (i == 2) ? now * m[i] : now + m[i];
            if (next < 0 || next > MAX) continue;
            if (arr[next] == 0) {
                arr[next] = arr[now] + 1;
                prev_node[next] = now;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n >> k;
    arr[n] = 1; prev_node[n] = -1;
    q.push(n);
    bfs();

    cout << arr[k] - 1 << '\n';
    while(prev_node[k] != -1) {
        path.push_back(k);
        k = prev_node[k];
    }
    cout << n << ' ';
    for(int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << ' ';
    }
}