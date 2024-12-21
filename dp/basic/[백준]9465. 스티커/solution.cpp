#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T, n;
    int a[2][100000];
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        
        a[0][1] += a[1][0];
        a[1][1] += a[0][0];
        for (int i = 2; i < n; i++) {
            a[0][i] += max(a[1][i - 1], a[1][i - 2]);
            a[1][i] += max(a[0][i - 1], a[0][i - 2]);
        }
        cout << max(a[0][n - 1], a[1][n - 1]) << '\n';
    }
}