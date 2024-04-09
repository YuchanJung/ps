#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n;
char arr[100][100];
bool visited[100][100] = {false};
// queue<vector<int>> q;
string s;
int res = 0, res_cow = 0;

void dfs(int x, int y, char color) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (!visited[nx][ny] && arr[nx][ny] == color) {
            visited[nx][ny] = true;
            dfs(nx, ny, color);
        }
    }
}

/*
void bfs(int sx, int sy) {
    // init
    q.push({sx, sy});
    visited[sx][sy] = true;
    char color = arr[sx][sy];
    // bfs
    while(!q.empty()) {
        vector<int> now = q.front(); q.pop();
        int x = now[0];
        int y = now[1];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (!visited[nx][ny] && color == arr[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) arr[i][j] = s[j];
    }
    
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j, arr[i][j]);
                res++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
            if (arr[i][j] == 'G') arr[i][j] = 'R';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j, arr[i][j]);
                res_cow++;
            }
        }
    }
    
    cout << res << ' ' << res_cow;
}