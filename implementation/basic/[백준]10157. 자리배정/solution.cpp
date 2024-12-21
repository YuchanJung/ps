#include <bits/stdc++.h>
using namespace std;

int c, r, k, d = 0;
int arr[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> c >> r >> k;
    if (c * r < k) {
        cout << 0;
        return 0;
    }
    int x = -1, y = 0, t = 0;
    while (true) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c || arr[nx][ny]) {
            d = (d + 1) % 4;
            continue;
        }
        arr[nx][ny] = ++t;
        x = nx; y = ny;
        if (t == k) {
            cout << ny + 1 << ' ' << nx + 1;
            break;
        }
    }
}