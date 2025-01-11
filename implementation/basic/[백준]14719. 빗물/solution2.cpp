#include <bits/stdc++.h>
using namespace std;

int h, w, res;
int blocks[500];

int main() {
    cin >> h >> w;

    for (int i = 0; i < w; i++)
        cin >> blocks[i];

    for (int i = 1; i < w - 1; i++) {
        int left = 0; int right = 0;
        //왼쪽 최대 값
        for (int j = 0; j < i; j++) left = max(left, blocks[j]);
        //오른쪽 최대 값
        for (int j = w - 1; j > i; j--) right = max(right, blocks[j]);
        //빗물 계산
        res += max(0, min(left, right) - blocks[i]);
    }

    cout << res;
    return 0;
}