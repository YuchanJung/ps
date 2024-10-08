#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

int n, res;
int a[MAX + 2], p[MAX + 2], q[MAX + 2];  

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    p[1] = q[n] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] > a[j]) p[i] = max(p[i], p[j] + 1);
        }
        int k = n - i + 1;
        for (int j = k + 1; j <= n + 1; j++) {
            if (a[k] > a[j]) q[k] = max(q[k], q[j] + 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        res = max(res, p[i] + q[i]);
    }
    cout << res - 1;
}
