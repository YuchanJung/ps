#include <bits/stdc++.h>

using namespace std;

int n, s, p;
int arr[50];

int main() {
    cin >> n >> s >> p;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int u = upper_bound(arr, arr + n, s) - arr;
    int l = lower_bound(arr, arr + n, s) - arr;
    if (n == 0) cout << 1;
    else if (l == 0 && n == p) cout << -1;
    else cout << n - u + 1;
}