#include <iostream>
#include <cstring>
#define MAX 3000000

using namespace std;

int n, m, k;
long long tree[MAX], treesize, start;

// void print_list() {
//     for(int i = 1; i <= treesize * 2 - 1; i++) {
//         cout << tree[i];
//     }
//     cout << '\n';
// }

void update(int idx, long long value) {
    int start = treesize + idx - 1;
    tree[start] = value; // update
    for (int i =  start / 2; i > 0; i /= 2) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

// 위에서 찾는 방식
// int preorder(int start, int end, int idx) {
//     if (start >= s && end <= n) {
//         return tree[idx];
//     }

// }


long long get_sum(int left, int right) {
    long long sum = 0;
    left = start + left - 1;
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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    treesize = 1;
    while (treesize < n) {
        treesize *= 2;
    }

    memset(tree, 0, sizeof(int) * treesize * 2); // ?
    start = treesize;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        tree[start + i] = x;
    }

    for (int i = start - 1; i > 0; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1]; 
    }

    for (int i = 0; i < m + k; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1){
            update(b, c);
        }
        else {
            cout << get_sum(b, c) << '\n';
        }
    }
    // print_list();
    // update(3, 6);
    // print_list();
    // cout << get_sum(3, 5);
    return 0;
}