#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m, ice, temp, k;
int arr[300][300];
int cnt[300][300];
int visited[300][300];

void melt() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > 0) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (arr[nx][ny] == 0) cnt[i][j]++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cnt[i][j] > 0) {
                arr[i][j] -= cnt[i][j];
                if (arr[i][j] <= 0) {
                    arr[i][j] = 0;
                    ice--;
                }
            }
        }
    }
}

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) continue;
        if (arr[nx][ny] > 0) {
            visited[nx][ny] = 1;
            temp++;
            dfs(nx, ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > 0) ice++;
        }
    }

    while (ice > 0) {
        k++;
        memset(cnt, 0, sizeof(cnt));
        memset(visited, 0, sizeof(visited));
        melt();
        temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] > 0 && !visited[i][j]) {
                    temp++;
                    visited[i][j] = 1;
                    dfs(i, j);

                    if (ice > temp) {
                        cout << k;
                        return 0;
                    }
                }
            }
        }
    }
    cout << 0;
    return 0;
}