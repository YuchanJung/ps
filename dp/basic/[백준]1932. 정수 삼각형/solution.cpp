#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int arr[500][500] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }
    int res = arr[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) arr[i][j] += arr[i - 1][j];
            else {
                arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
            }
            if (i == n - 1) res = max(res, arr[i][j]);
        }
    }
    cout << res;
}