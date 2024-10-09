#include <bits/stdc++.h>

using namespace std;

int n, m;
int r1, c1, r2, c2;
int arr[1025][1025];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i][j - 1] + arr[i - 1][j];
            arr[i][j] -= arr[i - 1][j - 1];
        }
    }

    while (m--) {
        cin >> r1 >> c1 >> r2 >> c2;
        // int res = arr[x2][y2];
        cout << arr[r2][c2] - arr[r2][c1 - 1] - arr[r1 - 1][c2] + arr[r1 - 1][c1 - 1] << '\n';
    }
}