#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int m[3] = {-1, 1, 2};

int arr[MAX + 1][2] = {0}; // distance, routes
int n, k;
int res = 0;
queue<int> q;

void bfs() {
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for (int i = 0; i < 3; i++) {
            int next = (i == 2) ? now * m[i] : now + m[i];
            if (next < 0 || next > MAX) continue;
            if (arr[next][0] == 0) {
                arr[next][0] = arr[now][0] + 1;
                arr[next][1] = arr[now][1];
                q.push(next);
            }
            else if (arr[next][0] == arr[now][0] + 1) 
                arr[next][1] += arr[now][1];
        }
    }
}

int main() {
    cin >> n >> k;
    arr[n][0] = arr[n][1] = 1;
    q.push(n);
    bfs();
    cout << arr[k][0] - 1 << '\n' << arr[k][1];
}