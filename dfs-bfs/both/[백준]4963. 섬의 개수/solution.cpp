#include <bits/stdc++.h>

using namespace std;

int w, h, res;
int arr[50][50];
int visited[50][50];
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void init() {
    memset(arr, 0, sizeof(arr));
    memset(visited, 0, sizeof(visited));
    res = 0;
}

void dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= h || ny >= w || !arr[nx][ny]) continue;
        if (!visited[nx][ny]) {
            visited[nx][ny] = 1;
            dfs(nx ,ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        init();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (arr[i][j] == 1 && visited[i][j] == 0) {
                    visited[i][j] = 1;
                    res++;
                    dfs(i, j);
                }
            }
        }
        cout << res << '\n';
    }
}