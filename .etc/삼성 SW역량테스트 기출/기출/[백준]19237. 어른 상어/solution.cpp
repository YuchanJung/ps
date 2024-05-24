#include <iostream>

using namespace std;

struct Shark {
    int x, y, d;
};

int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};

int arr[21][21][2]; // 상어 번호, 냄새 시간
int sd[401][4][4]; // 상어 번호, 상하좌우, 우선순위
int N, M, k, cnt;
Shark sh[401];

void weaken() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j][1] > 0) arr[i][j][1]--;
            if (arr[i][j][1] == 0) arr[i][j][0] = 0;
        }
    }
}

void move() {
    for (int i = 1; i <= M; i++) { // 1번 상어부터 차례대로 갱신
        if (sh[i].x == -1) continue; // 쫓겨난 상어
        int x = sh[i].x, y = sh[i].y, d = sh[i].d;
        int nd, nx, ny;
        bool flag = true;
        for (int j = 0; j < 4; j++) {
            nd = sd[i][d][j];
            nx = x + dx[nd];
            ny = y + dy[nd];
            if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
            if (arr[nx][ny][0] == 0) { // 상어 다음 좌표 계산
                sh[i].x = nx; sh[i].y = ny; sh[i].d = nd;
                flag = false;
                break;
            }
        }
        if (!flag) continue; 
        // 이동 가능한 칸 없을 때 
        for (int j = 0; j < 4; j++) {
            nd = sd[i][d][j];
            nx = x + dx[nd];
            ny = y + dy[nd];
            if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
            if (arr[nx][ny][0] == i) {  // 자신의 냄새가 있는 칸으로 다음 좌표 계산
                sh[i].x = nx; sh[i].y = ny; sh[i].d = nd;
                break;
            }
        }
    }
    // 번호 작은 순으로 다음 좌표로 이동
    for (int i = 1; i <= M; i++) {
        if (sh[i].x == -1) continue; // 쫓겨난 상어
        int x = sh[i].x, y = sh[i].y;
        if (arr[x][y][0] == 0 || arr[x][y][0] == i) {
            arr[x][y][0] = i;
            arr[x][y][1] = k + 1;
        }
        else { // 이미 이동한 상어 있으면
            sh[i].x = -1;
            sh[i].y = -1;
            cnt--;
        }
    }
}

int main() {
    cin >> N >> M >> k;
    cnt = M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int s;
            cin >> s;
            arr[i][j][0] = s;
            arr[i][j][1] = 0;
            if (s > 0) {
                sh[s].x = i;
                sh[s].y = j;
                arr[i][j][1] = k; // 냄새
            }
        }
    }
    for (int i = 1; i <= M; i++) {
        cin >> sh[i].d;
        sh[i].d--;
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < 4; j++) {
            for (int d = 0; d < 4; d++) {
                cin >> sd[i][j][d];
                sd[i][j][d]--;
            }
        }
    }
    int t = 1000;
    while (t--) {
        move();
        weaken();
        if (cnt == 1) {
            t = 1000 - t;
            break;
        }
    }
    if (t) cout << t;
    else cout << "-1";
}