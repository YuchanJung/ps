#include <bits/stdc++.h>
using namespace std;

int n, m, b, r1 = 99999999, r2;
int x, _max = -1, _min = 300;
int arr[500][500];

int getTime(int k) {
    int t = 0, plus = 0, minus = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = arr[i][j];
            if (x > k) {
                t += (x - k) * 2;
                plus += x - k;
            }
            else {
                t += k - x;
                minus += k - x;
            }
        }
    }
    if (minus - plus <= b) return t;
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> b; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 256; i >= 0; i--) {
        int t = getTime(i);
        if (t != -1 && r1 > t) {
            r1 = t;
            r2 = i;
        }
    }
    cout << r1 << ' ' << r2;
}