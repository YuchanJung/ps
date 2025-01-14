#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll res, n, m;
ll arr[1000001];
int mods[1000]; // # i: 나머지의 i인 칸의 개수

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        int mod = arr[i] % m;
        if (mod == 0) res++;
        res += mods[mod]++;
    }
    cout << res;
}