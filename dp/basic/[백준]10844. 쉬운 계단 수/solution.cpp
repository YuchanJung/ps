#include <bits/stdc++.h>
#define D 1000000000

using namespace std;

int main() {
    int a[101][10] = {0}, n;
    cin >> n;
    for (int i = 1; i < 10; i++) a[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        a[i][0] = a[i - 1][1] % D;
        a[i][9] = a[i - 1][8] % D;
        for (int j = 1; j < 9; j++) {
            a[i][j] = (a[i - 1][j - 1] + a[i - 1][j + 1]) %  D;
        }
    }

    int res = 0;
    for (int i = 0; i < 10; i++) {
        res += a[n][i];
        res %= D;
    }
    cout << res;
}