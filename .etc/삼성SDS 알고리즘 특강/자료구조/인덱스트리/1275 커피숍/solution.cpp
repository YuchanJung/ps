#include <iostream>
#include <cstdio>
#include <string.h>
#define MAX 3000000

using namespace std;
typedef long long ll;
int N, Q;
int x, y, a; ll b;
ll tree[MAX] = {0};
int treesize, start;


ll get_sum(int left, int right) {
    ll sum = 0;
    left = start + left  - 1;
    right = start + right - 1;
    while (left <= right) {
        if (left % 2 == 1) {
            sum += tree[left];
            left += 1;
        }
        if (right % 2 == 0) {
            sum += tree[right];
            right -= 1;
        }
        left /= 2;
        right /= 2;
    }
    return sum;
}

void update(int idx, ll value) {
    idx = start + idx - 1;
    tree[idx] = value;
    for (int i = idx / 2; i > 0; i /= 2) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> Q;

    treesize  = 1;
    while (treesize < N) {
        treesize *= 2;
    }
    start = treesize;

    // memset(tree, 0, sizeof(int) * treesize * 2);
    for (int i = 0; i < N; i++) {
        cin >> tree[start + i];
        // ll num;
        // cin >> num;
        // tree[start + i] = num;
    }

    for (int i = start - 1; i > 0; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    for (int i = 0; i < Q; i++) {
        cin >> x >> y >> a >> b;
        ll sum = (x < y) ? get_sum(x, y) : get_sum(y, x);
        cout << sum << '\n';
        update(a, b);
    }
}