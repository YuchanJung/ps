#include <bits/stdc++.h>
using namespace std;
const int MAX = 500001;
int n, a, b;
int arr[MAX], pre[MAX], isLis[MAX];
vector<int> lis = {-1};
vector<int> res;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr[a] = b;
    }
    for (int i = 1; i < MAX; i++) {
        int t = arr[i];
        if (t == 0) continue;

        int k = lower_bound(lis.begin(), lis.end(), t) - lis.begin();
        if (k == lis.size()) lis.push_back(t);
        else lis[k] = t;

        pre[t] = lis[k - 1];
    }

    int l = lis.size() - 1;
    cout << n - l << '\n';
    int v = lis[l];
    for (int i = 0; i < l; i++) {
        isLis[v] = 1;
        v = pre[v];
    }
    for (int i = 1; i < MAX; i++) {
        if (arr[i] != 0 && isLis[arr[i]] == 0) {
            res.push_back(i);
        }
    }
    sort(res.begin(), res.end());
    for (auto &v: res) cout << v << '\n';
}