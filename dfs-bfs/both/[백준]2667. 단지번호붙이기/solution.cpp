#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n;
int arr[25][25];
int res = 0;
int cnt = 0;
vector<int> v;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (arr[nx][ny] == 1) {
            arr[nx][ny] = 0;
            cnt++;
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') arr[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                res++;
                cnt = 1;
                arr[i][j] = 0;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << res << '\n';
    for (auto i: v) cout << i << '\n';
}