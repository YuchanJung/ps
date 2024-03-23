#include <iostream>
#include <algorithm>
#define MAX 500000

using namespace std;

typedef long long ll;
int N, H;
int tree[MAX+1] = {0};
ll prefix[MAX+1] = {0};

void update(int idx, int value) {
    while (idx <= H) {
        tree[idx] += value;
        idx += idx & -idx;
    }
}

ll query(int idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> H;

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        if (i % 2 == 1) {
            update(1, 1);
            update(x + 1, -1);
        }
        else {
            update(H - x + 1, 1);
        }
    }
    
    ll res = N;
    int cnt = 0;
    for (int i = 1; i <= H; i++) {
        prefix[i] = query(i);
        res = min(res, query(i));
    }
    for (int i = 1; i <= H; i++) {
        if (prefix[i] == res) cnt++;
    }
    cout << res << ' ' << cnt;  
}