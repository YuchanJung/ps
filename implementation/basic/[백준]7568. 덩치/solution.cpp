#include <bits/stdc++.h>

using namespace std;

int n;
int arr[50][2];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = 0; i < n; i++) {
        int k = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (arr[j][0] > arr[i][0] && arr[j][1] > arr[i][1]) k++;
        }
        cout << k << ' ';
    }
}