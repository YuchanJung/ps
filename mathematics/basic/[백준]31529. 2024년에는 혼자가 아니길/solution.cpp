#include <bits/stdc++.h>

using namespace std;

int X, Y, W;

int main() {
    cin >> X >> Y;
    int res = (2 * X - Y) * 506;
    if (res < 0) cout << -1;
    else if (X > Y) cout << -1;
    else cout << res;
}