#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int arr[10000];

int get_sum(int limit) {
    int s = 0;
    for (auto &c: arr) {
        if (c > limit) s += limit;
        else s += c;
    }
    return s;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (k < arr[i]) k = arr[i];
    }
    cin >> m;
    int left = 1, right = k;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (get_sum(mid) <= m) {
            k = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << k;
}