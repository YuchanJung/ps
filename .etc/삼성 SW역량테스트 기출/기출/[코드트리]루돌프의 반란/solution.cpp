#include <iostream>
#include <vector>

using namespace std;

int r_dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int r_dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int s_dx[4] = {0, 1, 0, -1}; // 좌하우상
int s_dy[4] = {-1, 0, 1, 0};

int N, M, P, C, D, cnt;
int rr, rc;
int sn, sr, sc;
int arr[51][51];
int score[31];
bool live[31];
int stop[31];
vector<int> s_loc[31];

int calc(int r1, int c1, int r2, int c2) {
    return (r1 - r2) * (r1 - r2) + (c1 - c2) * (c1 - c2);
}

void s_move(int idx, int x, int y, int dx, int dy) {
    if (x <= 0 || y <= 0 || x > N || y > N) {
        live[idx] = false;
        s_loc[idx][0] = -1; s_loc[idx][1] = -1;
        cnt--;
        return;
    }
    if (arr[x][y] > 0) {
        s_move(arr[x][y], x + dx, y + dy, dx, dy);
    }
    s_loc[idx][0] = x;
    s_loc[idx][1] = y;
    arr[x][y] = idx;
}

void r_turn(int k) {
    int dist = 99999;
    int idx = -1;
    // 가장 가까운 산타 찾기
    // cout << "루돌프 위치 : " << rr << ' ' << rc << '\n';
    for (int i = 1; i <= P; i++) {
        if (!live[i]) continue; // 탈락한 산타 제외
        int temp = calc(rr, rc, s_loc[i][0], s_loc[i][1]);
        bool flag = false;
        if (dist > temp) flag = true;
        else if (dist == temp && idx != -1) {
            if (s_loc[idx][0] < s_loc[i][0]) flag = true;
            else if (s_loc[idx][0] == s_loc[i][0] && s_loc[idx][1] < s_loc[i][1]) flag = true;
        }
        if (flag) {
            // cout << "갱신 중 : .." << dist << ' ' << idx << '\n';
            dist = temp;
            idx = i;
        }
    }
    int min_sr = s_loc[idx][0], min_sc = s_loc[idx][1];
    // cout << "루돌프가 제일 가까운 산타 : " << min_sr << ' ' << min_sc << '\n';
    // 이동
    dist = 99999;
    int d = -1;
    for (int i = 0; i < 8; i++) {
        int temp = calc(rr + r_dx[i], rc + r_dy[i], min_sr, min_sc);
        if (dist > temp) {
            dist = temp;
            d = i;
        }
    }
    arr[rr][rc] = 0;
    rr += r_dx[d];
    rc += r_dy[d];
    if (arr[rr][rc] >= 1) { // 루돌프가 산타 충돌
        score[idx] += C;
        min_sr += r_dx[d] * C;
        min_sc += r_dy[d] * C;
        stop[idx] = k + 1;
        s_move(idx, min_sr, min_sc, r_dx[d], r_dy[d]);
    }
    arr[rr][rc] = -1;
}

void s_turn(int k) {
    for (int i = 1; i <= P; i++) {
        if (!live[i] || stop[i] >= k) continue;
        // 루돌프에게 가까워지는 방향 찾기
        int dist = calc(rr, rc, s_loc[i][0], s_loc[i][1]);
        int d = -1;
        for (int j = 0; j < 4; j++) {
            int nx = s_loc[i][0] + s_dx[j];
            int ny = s_loc[i][1] + s_dy[j];
            if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue; // 게임판 밖
            if (arr[nx][ny] > 0) continue; // 다른 산타 있으면
            int temp = calc(rr, rc, nx, ny);
            if (dist >= temp) {
                dist = temp;
                d = j;
            }
        }
        if (d == -1) continue;// 움직일 수 없거나 움직여도 가까워질 수 없는 경우
        int nx = s_loc[i][0] + s_dx[d];
        int ny = s_loc[i][1] + s_dy[d];
        arr[s_loc[i][0]][s_loc[i][1]] = 0;
        if (arr[nx][ny] == -1) {
            score[i] += D;
            stop[i] = k + 1;
            d = (d + 2) % 4; // 반대로 밀려나는 방향;
            nx += s_dx[d] * D;
            ny += s_dy[d] * D;
            // cout << "밀려나유 : " << d << ' ' << nx << ' ' << ny << '\n' ;
            s_move(i, nx, ny, s_dx[d], s_dy[d]);

        } else {
            arr[nx][ny] = i;
            s_loc[i][0] = nx;
            s_loc[i][1] = ny;
        }
    }
    for (int i = 1; i <= P; i++) {
        if (live[i]) score[i] += 1;
    }
}


void print_arr() {
    cout << "Matrix : \n"; 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "coordinate : \n";
    for (int i = 1; i <= P; i++) {
        cout << i << ": " << s_loc[i][0] << ',' << s_loc[i][1] << '\n';
    }
    cout << "score : \n";
    for (int i = 1; i <= P; i++) {
        cout << score[i] << ' ';
    }
    cout << "\n산타 수 : " << cnt << '\n';
    cout << "==================\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> P >> C >> D;
    cin >> rr >> rc;
    arr[rr][rc] = -1;
    cnt = P;
    for (int i = 1; i <= P; i++) {
        cin >> sn >> sr >> sc;
        s_loc[sn] = {sr, sc};
        arr[sr][sc] = sn;
        live[i] = true;
        stop[i] = 0;
    }
    for (int i = 1; i <= M; i++) {
        if (cnt == 0) break;
        r_turn(i);
        s_turn(i);
    }
    
    for (int i = 1; i <= P; i++) {
        cout << score[i] << ' ';
    }
}