#include <bits/stdc++.h>

using namespace std;

int n, res;
int arr[1001][10];

int main() {
    cin >> n;
    for (int i = 0; i < 10; i++) arr[1][i] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                arr[i][k] += arr[i - 1][j];
                arr[i][k] %= 10007;
            }
        }
    }

    for (int i = 0; i < 10; i++) 
        res += arr[n][i];
    cout << res % 10007;
}
