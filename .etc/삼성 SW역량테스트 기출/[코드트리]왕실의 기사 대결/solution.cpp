#include <iostream>
#include <queue>

using namespace std;

struct Knight{
    int r, c, h, w, k;
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int L, N, Q;
int board[41][41], loc[41][41];
int res[31];
bool check[31];
Knight kn[31];
queue<int> q;

bool canMove(int idx, int d) {
    while(!q.empty()) q.pop();
    for (int i = 1; i <= N; i++) check[i] = false;

    q.push(idx);
    check[idx] = true;
    while(!q.empty()) {
        Knight k = kn[q.front()]; q.pop();
        int x = k.r, y = k.c, h = k.h, w = k.w;
        int nx = x + dx[d];
        int ny = y + dy[d];
        for (int i = nx; i < nx + h; i++) {
            for (int j = ny; j < ny + w; j++) {
                if (i <= 0 || j <= 0 || i > L || j > L || board[i][j] == 2) return false;
                if (loc[i][j] != idx && loc[i][j] > 0 && !check[loc[i][j]]) {
                    check[loc[i][j]] = true;
                    q.push(loc[i][j]);
                }
            }
        }
    }
    return true;
}


void move(int idx, int d) {
    Knight k = kn[idx];
    int x = k.r, y = k.c, h = k.h, w = k.w;
    int nx = x + dx[d];
    int ny = y + dy[d];
    for (int i = nx; i < nx + h; i++) {
        for (int j = ny; j < ny + w; j++) {
            if (loc[i][j] != idx && loc[i][j] > 0) {
                move(loc[i][j], d);
            }
        }
    }
    for (int i = x; i < x + h; i++) 
        for (int j = y; j < y + w; j++)
            loc[i][j] = 0;
    for (int i = nx; i < nx + h; i++) 
        for (int j = ny; j < ny + w; j++) 
            loc[i][j] = idx;
    kn[idx].r = nx; kn[idx].c = ny;
}

void damage(int idx) {
    for (int i = 1; i <= N; i++) {
        if (i == idx || !check[i] || kn[i].k <= 0) continue;
        int x = kn[i].r, y = kn[i].c, h = kn[i].h, w = kn[i].w;
        int cnt = 0;
        for (int r = x; r < x + h; r++) {
            for (int c = y; c < y + w; c++) {
                if (board[r][c] == 1) {
                    kn[i].k--;
                    res[i]++;
                }
            }
        }

        if (kn[i].k <= 0) {
            for (int r = x; r < x + h; r++)
                for (int c = y; c < y + w; c++)
                    loc[r][c] = 0;
        }
    }
}

int main() {
    cin >> L >> N >> Q;
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        int r, c, h, w, k;
        cin >> r >> c >> h >> w >> k;
        kn[i] = {r, c, h, w, k};
        for (int x = r; x < r + h; x++) {
            for (int y = c; y < c + w; y++) {
                loc[x][y] = i;
            }
        }
    }
    while (Q--) {
        int _i, _d;
        cin >> _i >> _d;
        if (kn[_i].k <= 0) continue; // 사라진 기사
        if (canMove(_i, _d)) { 
            move(_i, _d);
            damage(_i);
        }
    }
    int r = 0;
    for (int i = 1; i <= N; i++) {
        // cout << res[i] << ' ';
        if (kn[i].k > 0) r += res[i];
    }
    cout << r;
}