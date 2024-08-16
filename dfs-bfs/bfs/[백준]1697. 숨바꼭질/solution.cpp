// bfs
#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int m[3] = {-1, 1, 2};

int arr[MAX + 1] = {0};
int n, k;
queue<int> q;

void bfs() {
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for (int i = 0; i < 3; i++) {
            int next = (i == 2) ? now * m[i] : now + m[i];
            if (next < 0 || next > MAX) continue;
            if (arr[next] == 0) {
                arr[next] = arr[now] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n >> k;
    arr[n] = 1;
    q.push(n);
    bfs();
    cout << arr[k] - 1;
}
    

// dp
#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int main() {
    int arr[MAX + 1] = {0};
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        arr[n - i] = i;
    }

    for (int i = n + 1; i <= MAX; i++) {
        if (i % 2 == 0) {
            arr[i] = min(arr[i - 1], arr[i / 2]) + 1;
            arr[i - 1] = min(arr[i - 1], arr[i] + 1);
        }
        else {
            arr[i] = arr[i - 1] + 1;
        }
    }

    cout << arr[k];
}