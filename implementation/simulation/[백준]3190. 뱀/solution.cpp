// deque 이용한 풀이
#include <iostream>
#include <map>
#include <deque>
#define MAX 100

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    int n, k, l;
    int direction = 1; // right
    cin >> n >> k;
    int matrix[MAX][MAX] = {0};
    deque<pair<int, int>> d;
    d.push_front({0, 0});
    matrix[0][0] = 2;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        matrix[x - 1][ y - 1] = 1;
    }

    cin >> l;
    map<int, int> m;
    for (int i = 0; i < l; i++) {
        int x, d;
        char c;
        cin >> x >> c;
        d = (c == 'L') ? 3 : 1;
        m.insert({x, d});
    }

    int time = 0;
    while (true) {
        time++;
        int nx = d.front().first;
        int ny = d.front().second;
        nx += dx[direction];
        ny += dy[direction];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) break; // 벽
        if (matrix[nx][ny] == 2) break; // 자기자신

        if (matrix[nx][ny] == 0) {
            pair<int, int> p = d.back();
            matrix[p.first][p.second] = 0;
            d.pop_back();
        }
        d.push_front({nx, ny});
        matrix[nx][ny] = 2;

        if (m.find(time) != m.end()) {
            direction = (direction + m[time]) % 4;
        }
    }
    cout << time;
    return 0;
}

// 첫풀이
#include <iostream>
#include <map>
#define MAX 100

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    int n, k, l;
    int direction = 1; // right
    cin >> n >> k;
    int matrix[MAX][MAX] = {0};
    int head[2] = {0, 0};
    int tail[4] = {0, 0, 1, 0}; // x, y, direction, time
    matrix[0][0] = 2;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        matrix[x - 1][ y - 1] = 1;
    }

    cin >> l;
    map<int, int> m;
    for (int i = 0; i < l; i++) {
        int x, d;
        char c;
        cin >> x >> c;
        d = (c == 'L') ? -1 : 1;
        m.insert({x, d});
    }

    int time = 0;
    while (true) {
        time++;
        head[0] += dx[direction];
        head[1] += dy[direction];
        if (head[0] < 0 || head[1] < 0 || head[0] >= n || head[1] >= n) break; // 벽
        if (matrix[head[0]][head[1]] == 2) break; // 자기자신

        if (matrix[head[0]][head[1]] == 0) {
            matrix[tail[0]][tail[1]] = 0;

            if (m.find(tail[3]) != m.end()) {
                tail[2] = (tail[2] + m[tail[3]] + 4) % 4;
            }
            tail[0] += dx[tail[2]];
            tail[1] += dy[tail[2]];
            tail[3]++; 
        }
        matrix[head[0]][head[1]] = 2;

        if (m.find(time) != m.end()) {
            direction = (direction + m[time] + 4) % 4;
        }
    }
    cout << time;
    return 0;
}