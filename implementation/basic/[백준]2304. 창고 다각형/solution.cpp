#include <bits/stdc++.h>

using namespace std;

int n, s, res;
int arr[1100];
int m, mi;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> arr[s];
        if (arr[s] > m) {
            m = arr[s];
            mi = s;
        }
    }

    for (int i = 1; i < mi; i++) {
        if (arr[i] < arr[i - 1])
            arr[i] = arr[i - 1];
    }

    for (int i = 999; i > mi; i--) {
        if (arr[i] < arr[i + 1])
            arr[i] = arr[i + 1];
    }
    for (int i = 0; i <= 1000; i++) res += arr[i];

    cout << res;
}