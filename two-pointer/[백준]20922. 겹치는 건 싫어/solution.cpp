#include <bits/stdc++.h>

using namespace std;

int n, k, res;
int cnt[110000], arr[210000];
int s, e = -1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    while (e < n - 1) {
        if (cnt[arr[e + 1]] < k) {
            cnt[arr[e + 1]]++;
            e++;
        }
        else {
            cnt[arr[s]]--;
            s++;
        }
        res = max(res, e - s + 1);
    }

    cout << res;
}