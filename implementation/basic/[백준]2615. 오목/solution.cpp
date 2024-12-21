#include <bits/stdc++.h>
using namespace std;

int arr[21][21];
int dx[4] = {0, 1, 1, -1};
int dy[4] = {1, 1, 0, 1};

bool win(int x, int y, int k) {
    bool f[4] = {true, true, true, true};
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 5; j++) {
            if (arr[x + dx[i] * j][y + dy[i] * j] != k) f[i] = false;
        }
        if (arr[x - dx[i]][y - dy[i]] == k) f[i] = false;
        if (arr[x + dx[i] * 5][y + dy[i] * 5] == k) f[i] = false; 
    }
    return f[0] || f[1] || f[2] || f[3];
}

int main() {
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
            cin >> arr[i][j];
    
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            int k = arr[j][i];
            if (k && win(j, i, k)) {
                cout << k << '\n' << j << ' ' << i;
                return 0;
            }
        }
    }
    cout << 0;
}