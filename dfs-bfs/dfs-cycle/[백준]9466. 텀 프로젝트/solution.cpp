#include <bits/stdc++.h>
using namespace std;

int t, n, no, res;
int arr[100001], v[100001], f[100001];

void dfs(int n) {
    int next = arr[n];
    if (!v[next]) {
        v[next] = ++no;
        dfs(next);
    }
    else if (!f[next]) {
        res += (v[n] - v[next] + 1);
    }
    f[n] = 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while (t--) {
        memset(v, 0, sizeof(v));
        memset(f, 0, sizeof(f));
        no = res = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        for (int i = 1; i <= n; i++) {
            if (!v[i]) {
                v[i] = ++no;
                dfs(i);
            }
        }
        cout << n - res << '\n';
    }
}