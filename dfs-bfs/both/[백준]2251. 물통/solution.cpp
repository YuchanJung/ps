#include <bits/stdc++.h>
using namespace std;

int _max[3];
bool visited[201][201][201];
set<int> res;

void dfs(vector<int> now, int idx) {
    int t = now[idx];
    for (int i = 0; i < 3; i++) {
        if (i == idx || now[i] == _max[i]) continue;
        int d = _max[i] - now[i];
        int amount = (t <= d) ? t : d;
        vector<int> next(now);
        next[idx] -= amount;
        next[i] += amount;
        if (visited[next[0]][next[1]][next[2]]) continue;
        if (!next[0]) res.insert(next[2]);
        visited[next[0]][next[1]][next[2]] = true;
        for (int i = 0; i < 3; i++) {
            if (next[i]) dfs(next, i);
        }
    }
}

int main() {
    cin >> _max[0] >> _max[1] >> _max[2];
    visited[0][0][_max[2]] = true;
    res.insert(_max[2]);
    
    dfs({0, 0, _max[2]}, 2);
    for (auto &n: res) {
        cout << n << ' ';
    }
}