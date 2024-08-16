#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n, m, res = 1;
int arr[100][100];
int visited[100][100];

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (!visited[nx][ny] && arr[nx][ny]) {
            visited[nx][ny] = 1;
            dfs(nx, ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { 
            cin >> arr[i][j];
            m = max(arr[i][j], m);
        }
    }
    
    for (int k = 1; k <= m; k++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] <= k) arr[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] && !visited[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        res = max(res, cnt);
    }
    cout << res;
}