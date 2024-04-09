#include <iostream>
#include <queue>

using namespace std;

struct Pos {
    int x, y, v;
    Pos(int _x, int _y, int _v): x(_x), y(_y), v(_v) {}
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int R, C, T, res;
int arr[50][50];
int m1, m2; // 기계 위치
queue<Pos> q;

void spread() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] > 0) q.push(Pos(i, j, arr[i][j]));
        }
    }
    int l = q.size();
    while (l--) {
        Pos now = q.front(); q.pop();
        int amount = now.v / 5;
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (arr[nx][ny] == -1) continue;
            arr[nx][ny] += amount;
            arr[now.x][now.y] -= amount;
        }
    }
}

void clean(int x, int y) {
    int nx = -1, ny = -1;
    if ((x == 0 || x == R - 1) && y < C - 1) {
        nx = x;
        ny = y + 1;
    } else if ((x == m1 || x == m2) && y > 1) {
        nx = x;
        ny = y - 1;
    } else if ((y == 0 && x > 0 && x < m1) || (y == C - 1 && x > m2 && x < R)) {
        nx = x - 1;
        ny = y;
    } else if ((y == 0 && x > m2 && x < R) || (y == C - 1 && x >= 0 && x < m1)) {
        nx = x + 1;
        ny = y;
    }
    if (nx != -1) {
        arr[x][y] = arr[nx][ny];
        arr[nx][ny] = 0;
        clean(nx, ny);
    }
}

void work() {
    int x = m1 - 1, y = 0;
    while(true) {
        if (x == m1 && y == 1) {
            arr[x][y] = 0;
            break;
        }
        if (x - 1 >= 0 && y == 0) {
            arr[x][y] = arr[x - 1][y];
            x--;
        } else if (x == 0 && y != C - 1) {
            arr[x][y] = arr[x][y + 1];
            y++;
        } else if (y == C - 1 && x != m1) {
            arr[x][y] = arr[x + 1][y];
            x++;
        } else if (x == m1 && y > 1) {
            arr[x][y] = arr[x][y - 1];
            y--;
        }
    }
    x = m2 + 1; y = 0;
    while (true) {
        if (x == m2 && y == 1) {
            arr[x][y] = 0;
            break;
        }
        if (x - 1 >= m2 && y == C - 1) {
            arr[x][y] = arr[x - 1][y];
            x--;
        } else if (x == R - 1 && y != C - 1) {
            arr[x][y] = arr[x][y + 1];
            y++;
        } else if (x > m2 && x + 1 != R && y == 0) {
            arr[x][y] = arr[x + 1][y];
            x++;
        } else if (x == m2 && y > 1) {
            arr[x][y] = arr[x][y - 1];
            y--;
        }
    }

}


int main() {
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) {
                if (m1 == 0) m1 = i;
                else m2 = i;
            }
        }
    }

    while (T--) {
        spread();
        // work();
        clean(m1 - 1, 0);
        clean(m2 + 1, 0);
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] > 0) res += arr[i][j];
        }
    }
    cout << res;
}
