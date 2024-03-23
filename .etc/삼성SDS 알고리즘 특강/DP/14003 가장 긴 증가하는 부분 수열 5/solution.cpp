#include <cstdio>
#include <algorithm>
#define MAX 1000000

using namespace std;

int N, arr[MAX + 1], enum_arr[MAX + 1][2]; // value, index
int tree[MAX * 3][2] = {0}, start = 1; // LIS_value, cnt
int temp_idx, temp_value;
int ans[MAX + 1];

int prev_node[MAX + 1] = {0};

int comp(const void *arg1, const void *arg2) {
    int *a = (int*)arg1;
    int *b = (int*)arg2;
    if (a[0] != b[0]) return a[0] - b[0];
    else return b[1] - a[1]; // 역순 없으면 오류
}

void get(int left, int right) {
    temp_idx = 1;
    temp_value = 0;
    while (left <= right) {
        if (left % 2 == 1) {
            if (tree[left][0] >  temp_value) {
                temp_idx = tree[left][1];
                temp_value = tree[left][0];
            }
            left += 1; // if 문 바깥에 !
        }
        if (right % 2 == 0) {
            if (tree[right][0] >  temp_value) {
                temp_idx = tree[right][1];
                temp_value = tree[right][0];
            }
            right -= 1; // if 문 바깥에 !
        }
        left /= 2;
        right /= 2;
    }
}

void update(int idx, int value) {
    tree[idx][0] = value;
    tree[idx][1] = idx;
    for (int i = idx / 2; i > 0; i /= 2) {
        int greater_child;
        if (tree[i * 2][0] > tree[i * 2  + 1][0]) greater_child = i * 2;
        else greater_child = i * 2 + 1;
        
        tree[i][0] = tree[greater_child][0];
        tree[i][1] = tree[greater_child][1];
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        enum_arr[i][0] = arr[i];
        enum_arr[i][1] = i;
    }

    while (start < N) start *= 2;
    
    qsort(enum_arr, N, sizeof(int)*2, comp);

    for (int i = 0; i < N; i++) {
        // int value = enum_arr[i][0];
        int idx = enum_arr[i][1];
        get(start, start + idx - 1);
        prev_node[idx] = temp_idx - start;
        update(start + idx, temp_value + 1);
    }

    printf("%d\n", tree[1][0]);

    int cur = tree[1][1] - start;
    for (int i = tree[1][0] - 1; i >= 0; i--) {
        ans[i] = arr[cur];
        cur = prev_node[cur];
    }

    for (int i = 0; i < tree[1][0]; i++) {
        printf("%d ", ans[i]);
    }
}