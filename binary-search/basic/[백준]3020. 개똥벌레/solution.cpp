#include <bits/stdc++.h>
using namespace std;

int n, h, k, cnt, res = 999999;
vector<int> p, q;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (i % 2 == 0) p.push_back(k);
        else q.push_back(k);
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    for (int i = 1; i <= h; i++) {
        int temp = 0;
        temp += p.end() - lower_bound(p.begin(), p.end(), i);
        temp += q.end() - lower_bound(q.begin(), q.end(), h - i + 1);
        if (res > temp) {
            res = temp;
            cnt = 1;
        }
        else if (res == temp) cnt++;
    }
    cout << res << ' ' << cnt;
}