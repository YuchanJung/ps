#include <bits/stdc++.h>

using namespace std;

int N, p, r, res;
vector<int> v[50];

void dfs(int n) {
    if (n == p) return;
    int s = v[n].size();
    if (s == 0) {
        res++;
    }
    else if (s == 1 && v[n][0] == p) {
        res++;
    }
    else {
        for (int i = 0; i < s; i++) {
            dfs(v[n][i]);
        } 
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p;
        if (p == -1) {
            r = i;
            continue;
        }
        v[p].push_back(i);
    }
    cin >> p;
    dfs(r);
    cout << res;
}