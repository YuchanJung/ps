#include <bits/stdc++.h>

using namespace std;

int n, m, k, x, res;
int h[51];
vector<int> p[50];

int main() {
    cin >> n >> m;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x;
        h[x] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> x;
            p[i].push_back(x);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            bool flag = true;
            for (auto &s: p[j]) {
                if (h[s]) flag = false;
            }
            if (flag) continue;
            for (auto &s: p[j])
                h[s] = 1;
        }
    }
    
    for (int i = 0; i < m; i++) {
        bool flag = true;
        for (auto &s: p[i]) {
            if (h[s]) flag = false;
        }
        if (flag) res++;
    }
    cout << res;
}