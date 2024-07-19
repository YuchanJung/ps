#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll k, n, m, res;
int arr[10000];

int cal(int l) {
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        cnt += (arr[i] / l);
    }
    return cnt;
}

int main() {
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        if (arr[i] > m) m = arr[i];
    }

    ll left = 1, right = m;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll temp = cal(mid);
        if (temp < n) {
            right = mid - 1;
        }
        else {
            res = max(res, mid);
            left = mid + 1;
        }
    }
    cout << res;
}