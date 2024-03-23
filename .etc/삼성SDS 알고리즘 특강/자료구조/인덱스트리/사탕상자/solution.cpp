#include <iostream>
#define MAX 1000000

using namespace std;

int n;
int tree[MAX*3] = {0};
int treesize, start;
int a, b, c;

void update(int idx, int value) {
    tree[idx] += value;
    for (int i = idx / 2; i > 0; i /= 2) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

int find(int idx, int value) {
    if (idx >= start) return idx;

    int next = idx * 2;

    if (tree[next] < value) {
        return find(next + 1, value - tree[next]);
    }
    else {
        return find(next, value);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    treesize = 1;
    while (treesize < MAX) {
        treesize *= 2;
    }
    
    start = treesize;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 2) {
            cin >> b >> c;
            int idx = start + b - 1;
            update(idx, c);
        }
        else { // a == 1
            cin >> b;
            int idx = find(1, b);
            // 찾고 인덱스 반환해서 다시 업데이트
            // 찾으면서 -1 하지말자
            update(idx, -1);
            cout << idx - start + 1 << '\n';
        }
    }
}