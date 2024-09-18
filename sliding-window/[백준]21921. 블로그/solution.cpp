#include <bits/stdc++.h>

using namespace std;

int n, x;
int arr[250000];
int r, c, temp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < x; i++) {
        temp += arr[i];
    }
    r = temp;
    c = 1;

    for (int i = x; i < n; i++) {
        temp += arr[i];
        temp -= arr[i - x];
        if (r < temp) {
            r = temp;
            c = 1;
        }
        else if (r == temp) {
            c++;
        }
    }

    // 누적합
    /*
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i != 0 ) arr[i] += arr[i - 1];
    }

    r = arr[x - 1];
    c = 1;
    for (int i = x; i < n; i++) {
        temp =  arr[i] - arr[i - x];
        if (r < temp) {
            r = temp;
            c = 1;
        }
        else if (r == temp) {
            c++;
        }
    }
    */

    if (r == 0) cout << "SAD";
    else cout << r << '\n' << c;
}