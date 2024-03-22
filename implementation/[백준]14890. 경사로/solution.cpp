// 첫 풀이
#include <iostream>
#include <cstring>
#define MAX 100

using namespace std;

int N, L;
int matrix[MAX][MAX];
int matrix_T[MAX][MAX];
int cnt = 0;

void init() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            matrix[i][j] = x;
            matrix_T[j][i] = x;
        }
    }
}

int check(int arr[]) {
    int *block = new int[N];
    memset(block, 0, sizeof(int)*N);
    int cur = arr[0];
    int i = 1, j;
    while (i < N) {
        if (arr[i] == cur + 1) {
            // 상승 경사로 검사
            for (j = 1; j <= L; j++) {
                int ind = i - j;
                if (ind >= 0 && arr[ind] == cur && block[ind] == 0) 
                    continue;  
                return 0;
            }
            // 상승 경사로 기록
            for (j = 1; j <= L; j++) {
                block[i - j] = 1;
            }
            cur += 1;
            i++;
        }
        else if (arr[i] == cur - 1) {
            // 하강 경사로 검사
            for (j = 0; j < L; j++) {
                int ind = i + j;
                if (ind < N && arr[ind] == cur - 1 && block[ind] == 0)
                    continue;
                return 0;
            }
            // 하강 경사로 기록
            for (j = 0; j < L; j++) {
                block[i + j] = 1;
            }
            cur -= 1;
            i += L - 1;
        }
        else if (arr[i] == cur) {
            i++;
        }
        else {
            return 0;
        }
    }
    delete[] block;
    return 1;
}

void solve() {
    for (int i = 0; i < N; i++) {
        if (check(matrix[i])) cnt++;
        if (check(matrix_T[i])) cnt++;
    }
}

int main() {
    init();
    solve();
    cout << cnt;
    return 0;
}