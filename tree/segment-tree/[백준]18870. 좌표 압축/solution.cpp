// sort
#include <bits/stdc++.h>

using namespace std;

int n;
int res[1000000];
vector<pair<int, int>> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    res[v[0].second] = cnt;
    for (int i = 1; i < n; i++) {
        if (v[i].first != v[i - 1].first) cnt++;
        res[v[i].second] = cnt;
    }
    for (int i = 0; i < n; i++) cout << res[i] << ' ';
}

// set
#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

int n;
int a[MAX], r[MAX];
vector<int> v;
set<int> s;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    vector<int> v(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        r[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }

    for (int i = 0; i < n; i++) cout << r[i] << ' ';
}