#include <iostream>
#define MAX 20

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

int main() {
    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;
    int matrix[MAX][MAX] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    int dice[4][3] = {0};
    
    for (int i = 0; i < K; i++) {
        int direction;
        cin >> direction;
        int nx = x + dx[direction - 1];
        int ny = y + dy[direction - 1];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        
        x = nx; y = ny;
        if (direction == 4) {
            int temp = dice[0][1];
            for (int j = 0; j < 3; j++) {
                dice[j][1] = dice[j + 1][1];
            }
            dice[3][1] = temp;
        }
        else if (direction == 3) {
            int temp = dice[3][1];
            for (int j = 3; j > 0; j--) {
                dice[j][1] = dice[j - 1][1];
            }
            dice[0][1] = temp;
        }
        else if (direction == 2) {
            int temp = dice[1][0];
            for (int j = 0; j < 2; j++) {
                dice[1][j] = dice[1][j + 1];
            }
            dice[1][2] = dice[3][1];
            dice[3][1] = temp;
        }
        else {
            int temp = dice[1][2];
            for (int j = 2; j > 0; j--) {
                dice[1][j] = dice[1][j - 1];
            }
            dice[1][0] = dice[3][1];
            dice[3][1] = temp;
        }

        if (matrix[x][y] == 0) {
            matrix[x][y] = dice[3][1];
        }
        else {
            dice[3][1] = matrix[x][y];
            matrix[x][y] = 0;
        }
        cout << dice[1][1] << endl;
    }

    return 0;
}