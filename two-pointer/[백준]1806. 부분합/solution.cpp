#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

typedef long long ll;

ll arr[MAX];
ll n, s, res = MAX;
ll l, r = 1;

int main() {    
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    while (l < r && r <= n) {
        ll x = arr[r] - arr[l];
        if (x >= s) {
            res = min(res, r - l);
            l++;
        }
        else if (x < s) {
            r++;
        }
    }
    if (res == MAX) cout << 0;
    else cout << res;
}