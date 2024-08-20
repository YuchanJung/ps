#include <bits/stdc++.h>

using namespace std;

int n, a[10], res[10];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        int idx = i;
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (res[j] != 0) continue;
            if (++c == a[i] + 1) {
                idx = j;
                break;
            }
        }
        res[idx] = i + 1;
    }

    for (int i = 0; i < n; i++) cout << res[i] << ' ';
}

/*
#include <bits/stdc++.h>

using namespace std;

int n, a[11], k;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        int p = 1;
        while (k--) {
            while (a[p]) p++;
            p++;
        }
        while (a[p]) p++;
        a[p] = i;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}
*/