#include <iostream>
#include <algorithm>
#define MAX 300000
#define INF 2000000000

using namespace std;

int N, M, a, b;
int tree[MAX][2] = {0}; // min, max
int treesize, start;

void print_tree() {
    for (int i = 1; i <= treesize * 2; i++) {
        cout << tree[i][0] << ' ' << tree[i][1] << '\n';
    }
}

void get_min_max(int left, int right) {
    int min_num = INF;
    int max_num = 0;
    left = start + left - 1;
    right = start + right - 1;
    while (left <= right) {
        if (left % 2 == 1) {
            min_num = min(min_num, tree[left][0]);
            max_num = max(max_num, tree[left][1]);
            left += 1;
        }
        if (right % 2 == 0) {
            min_num = min(min_num, tree[right][0]);
            max_num = max(max_num, tree[right][1]);
            right -= 1;
        }
        left /= 2;
        right /= 2;
    }
    cout << min_num << ' ' << max_num << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    treesize = 1;
    while (treesize < N) {
        treesize *= 2;
    }
    start = treesize;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        tree[start + i][0] = tree[start + i][1] = num;
    }

    for (int i = start - 1; i > 0; i--) {
        // min
        int left = tree[i * 2][0];
        int right = tree[i * 2 + 1][0];
        int res;
        if (left == 0 && right == 0) res = 0;
        else if (left == 0) res = right;
        else if (right == 0) res = left;
        else res = min(left, right);
        tree[i][0] = res;
        // max
        tree[i][1] = max(tree[i * 2][1], tree[i * 2 + 1][1]);
    }
    
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        get_min_max(a, b);
        // (a < b) ? get_min_max(a, b) : get_min_max(b, a);
    }
}