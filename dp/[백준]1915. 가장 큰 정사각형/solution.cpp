#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

int n, m, res;
int arr[MAX + 1][MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = s[j - 1] - '0';
            if (arr[i][j] == 1) {
                arr[i][j] = min({arr[i - 1][j - 1], arr[i][j - 1], arr[i - 1][j]}) + 1;
            }
            res = max(res, arr[i][j]);
        }
    }
    cout << res * res;
}
