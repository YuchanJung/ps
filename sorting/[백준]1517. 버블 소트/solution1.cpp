// merge sort
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[500000], sorted[500000];
long long res;

void merge(int start, int end) {
    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            sorted[k++] = arr[i++];
        }
        else {
            res += mid - i + 1;
            sorted[k++] = arr[j++];
        }
    }
    while (i <= mid)
        sorted[k++] = arr[i++];
    while (j <= end)
        sorted[k++] = arr[j++];

    for (int i = start; i <= end; i++)
        arr[i] = sorted[i];
}

void merge_sort(int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, end);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(0, n - 1);
    cout << res;
}