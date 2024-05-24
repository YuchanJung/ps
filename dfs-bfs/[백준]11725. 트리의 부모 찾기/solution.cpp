#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int N;
vector<int> t[MAX];
int v[MAX];
int p[MAX];

void dfs(int r) {
    for (int i = 0; i < t[r].size(); i++) {
        int next = t[r][i];
        // cout << next << '\n';
        if (v[next]) continue;
        p[next] = r;
        v[next] = 1;
        dfs(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    v[1] = 1;
    dfs(1);
    for (int i = 2; i <= N; i++) {
        cout << p[i] << '\n';
    }
}