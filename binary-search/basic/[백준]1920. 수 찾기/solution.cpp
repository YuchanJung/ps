#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int arr[100000];

int bs(int t) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == t) return 1;
        if (arr[mid] < t) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        cout << bs(k) << '\n';
    }
}