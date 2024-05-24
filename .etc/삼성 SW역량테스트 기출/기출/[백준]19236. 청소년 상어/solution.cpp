#include <iostream>
#include <algorithm>

using namespace std;

int dx[8] = {-1 ,-1 ,0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1,};

void print_arr(int arr[][4][2]) {
    cout << "===================\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j][0] << ' ' << arr[i][j][1] << ' ';
        }
        cout << '\n';
    }
}

void fish_move(int arr[][4][2], int pos[][2]) {
    for (int i = 1; i <= 16; i++) {
        int x = pos[i][0], y = pos[i][1];
        if (x == -1 && y == -1) continue; // 먹혔으면

        bool flag = false;
        int d = arr[x][y][1];
        for (int j = 1; j < 8; j++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) d = (d + 1) % 8;
            else if (arr[nx][ny][0] == -1) d = (d + 1) % 8;
            else {
                bool flag = true;
                break;
            }
        }
        if (flag) continue; // 이동 불가
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (arr[nx][ny][0] > 0) { // 물고기가 있으면 swap
            arr[x][y][0] = arr[nx][ny][0];
            arr[x][y][1] = arr[nx][ny][1];
            pos[arr[x][y][0]][0] = x;
            pos[arr[x][y][0]][1] = y; 
        } else { // 물고기 없으면 기존 칸 0으로 바꿔주기 (실수 조심)
            arr[x][y][0] = 0;
            arr[x][y][1] = -1;
        }
        // 이동
        arr[nx][ny][0] = i;
        arr[nx][ny][1] = d;
        pos[arr[nx][ny][0]][0] = nx;
        pos[arr[nx][ny][0]][1] = ny; 
    }
}

int dfs(int arr[][4][2], int pos[][2], int x, int y) {
    int s = arr[x][y][0], d = arr[x][y][1];
    pos[s][0] = -1, pos[s][1] = -1; arr[x][y][0] = -1;
    fish_move(arr, pos);
    arr[x][y][0] = 0;
    int temp = 0;
    for (int i = 0; i < 3; i++) {
        x += dx[d];
        y += dy[d];
        if (x < 0 || y < 0 || x >= 4 || y >= 4) continue;
        int k = arr[x][y][0];
        if (k > 0) {
            int arr_copy[4][4][2], pos_copy[17][2];
            copy(&arr[0][0][0], &arr[0][0][0] + 32, &arr_copy[0][0][0]);
            copy(&pos[0][0], &pos[0][0] + 34, &pos_copy[0][0]);
            temp = max(temp, dfs(arr_copy, pos_copy, x, y));
        }
    }
    return s + temp;
}

int main() {
    int arr[4][4][2];
    int pos[17][2];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int x, d;
            cin >> x >> d;
            arr[i][j][0] = x;
            arr[i][j][1] = --d;
            pos[x][0] = i; pos[x][1] = j;
        }
    }
    cout << dfs(arr, pos, 0, 0);
}