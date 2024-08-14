#include <bits/stdc++.h>

using namespace std;

int n, d, k, c, cnt, res;
int arr[40000];
map<int, int> m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < k; i++) arr[n + i] = arr[i];

    for (int i = 0; i < k; i++) {
        if (m.find(arr[i]) == m.end()) {
            m.insert({arr[i], 1});
            cnt++;
        }
        else {
            m[arr[i]]++;
        }
    }
    if (m.find(c) == m.end()) {
        m.insert({c, 1});
        cnt++;
    }
    else m[c]++;

    for (int i = k; i < n + k; i++) {
        if (m.find(arr[i]) == m.end()) {
            m.insert({arr[i], 1});
            cnt++;
        }
        else m[arr[i]]++;

        m[arr[i - k]]--;
        if (m[arr[i - k]] == 0) {
            m.erase(arr[i - k]);
            cnt--;
        }
        res = max(res, cnt);
    }
    cout << res;
}
