#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int n, m;
long long arr[MAX];
int c;
long long k, _i, _j;
int res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < m; i++) {
        cin >> c;
        if (c == 3) {
            cin >> _i >> _j;
            res = upper_bound(arr, arr + n, _j) - lower_bound(arr, arr + n, _i);
        }
        else if (c == 2){
            cin >> k;
            res = upper_bound(arr, arr + n, k) - arr;
            res = n - res;
        }
        else {
            cin >> k;
            res = lower_bound(arr, arr + n, k) - arr;
            res = n - res;
        }
        cout << res << "\n";
    }

}