#include <bits/stdc++.h>
using namespace std;

int h[200], r[200];
int n, k, n2, s, e, cnt;

void rotate() {
    s = (s - 1 + n2) % n2;
    e = (e - 1 + n2) % n2;
    if (r[e]) r[e] = 0;
}

void move() {
    int c = e;
    for (int i = 0; i < n - 1; i++) {
        int nc = (c - 1 + n2) % n2;
        if (r[nc] && r[c] == 0 && h[c] > 0) {
            h[c] -= 1;
            if (h[c] == 0) cnt++;
            r[c] = 1;
            r[nc] = 0;
            if (c == e) r[c] = 0;
        }
        c = nc;
    }
}

void load() {
    if (h[s] > 0) {
        r[s] = 1;
        h[s] -= 1;
        if (h[s] == 0) cnt++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    n2 = n * 2;
    for (int i = 0; i < n2; i++) cin >> h[i];

    s = 0; e = n - 1;
    int res = 1;
    while (true) {
        rotate();
        move();
        load();
        if (cnt >= k) {
            cout << res;
            break;
        }
        res += 1;
    }
}