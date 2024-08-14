#include <bits/stdc++.h>

using namespace std;

int h, w, res;
int blocks[500];
int k;

int main() {
    cin >> h >> w;
    for (int i = 0; i < w; i++) {
        cin >> blocks[i];
    }

    for (int i = 0; i < h; i++) {
        int start = -1;
        for (int j = 0; j < w; j++) {
            if (blocks[j] >= h - i) {
                if (start != -1) {
                    res += j - start - 1;
                }
                start = j;
            }
        }
        // cout << res << '\n';
    }
    cout << res;
}