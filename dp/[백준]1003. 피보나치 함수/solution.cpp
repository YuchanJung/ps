#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, T;
    int arr[41][2] = {0};
    cin >> T;
    arr[0][0] = arr[1][1] = 1;
    for (int i = 2; i <= 40; i++) {
        arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
        arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
    }

    while(T--) {
        cin >> n;
        cout << arr[n][0] << ' ' << arr[n][1] << '\n';
    }
}
