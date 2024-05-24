#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
    int x, y;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, res;
int arr[8][8];
vector<Pos> v;
vector<Pos> nv;
vector<vector<int>> c;
vector<int> cArr(3);

void comb(int depth, int next) {
    if (depth == 3) {
        c.push_back(cArr);
        return;
    }
    for (int i = next; i <= nv.size() - 1; i++) {
        cArr[depth] = i;
        comb(depth + 1, i + 1);
    }
}

void dfs(int arr[][8], int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (arr[nx][ny] == 0) {
            arr[nx][ny] = 2;
            dfs(arr, nx, ny);
        }
    }
}

void solve() {
    for (int i = 0; i < c.size(); i++) {
        int arr_copy[8][8];
        copy(&arr[0][0], &arr[0][0] + 64, &arr_copy[0][0]);
        for (int j = 0; j < 3; j++) { // 벽 세우기
            int x = nv[c[i][j]].x;
            int y = nv[c[i][j]].y;
            arr_copy[x][y] = 1;
        }
        for (int k = 0; k < v.size(); k++) {
            dfs(arr_copy, v[k].x, v[k].y);
        }
        int tmp = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (arr_copy[r][c] == 0) tmp++;
            }
        }
        res = max(res, tmp);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) v.push_back({i, j});
            if (arr[i][j] == 0) nv.push_back({i, j});
        }
    }
    comb(0, 0);
    solve();
    cout << res;
}