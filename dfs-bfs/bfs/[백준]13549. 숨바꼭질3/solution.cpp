#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int m[3] = {-1, 1, 2};

int arr[MAX + 1] = {0}; // distance, routes
int n, k;
queue<int> q;

void bfs() {
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for (int i = 0; i < 3; i++) {
            int next = (i == 2) ? now * m[i] : now + m[i];
            if (next < 0 || next > MAX) continue;
            if (arr[next] > arr[now]) {
                arr[next] = (i == 2) ? arr[now] : arr[now] + 1;
                q.push(next);
            }
        }
    }
}

/*
void bfs_01() {
    while(!dq.empty()) {
        int now = dq.front(); dq.pop_front();
        for (int i = 0; i < 3; i++) {
            int next = (i == 2) ? now * m[i] : now + m[i];
            if (next < 0 || next > MAX) continue;
            if (arr[next] > arr[now]) {
                if (i == 2) {
                    arr[next] = arr[now];
                    dq.push_front(next); dq_cnt++;
                }
                else {
                    arr[next] = arr[now] + 1;
                    dq.push_back(next); dq_cnt++;
                }
            }
        }
    }
}
*/

int main() {
    cin >> n >> k;
    for (int i = 0; i <= MAX; i++) arr[i] = MAX * 2;
    arr[n] = 1;
    q.push(n);
    bfs();
    cout << arr[k] - 1;
}