#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

int main() {
    int n;
    int arr[MAX + 1];
    arr[1] = 0;

    cin >> n;
    for (int i = 2; i <= MAX; i++) {
        int temp = arr[i - 1];
        if (i % 3 == 0) temp = min(temp, arr[i/3]);
        if (i % 2 == 0) temp = min(temp, arr[i/2]);
        arr[i] = temp + 1;
    }

    cout << arr[n];
}