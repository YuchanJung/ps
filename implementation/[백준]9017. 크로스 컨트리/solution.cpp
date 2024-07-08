#include <bits/stdc++.h>
#define MAX 999999

using namespace std;

int t, n, m, res;

int main() {
    cin >> t;
    while (t--) {
        int arr[1000] = {0}, score[201][2] = {0}, cnt[201] = {0};
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            cnt[arr[i]] += 1;
            m = max(m, arr[i]);
        }
        for (int i = 1; i <= m; i++) 
            if (cnt[i] < 6) 
                score[i][0] = MAX;

        int s = 1;
        for (int i = 0; i < n; i++) {
            int idx = arr[i];
            if (score[idx][0] == MAX) continue;
            if (cnt[idx] > 2)
                score[idx][0] += s; 
            if (cnt[idx] == 2) 
                score[idx][1] = s;
            cnt[idx]--;
            s++;
        }

        int *p = score[1];
        res = 1;
        for (int i = 1; i <= m; i++) {
            if (p[0] > score[i][0]) {
                p = score[i];
                res = i;
            }
            else if (p[0] == score[i][0]) {
                if (p[1] > score[i][1]) {
                    p = score[i];
                    res = i;
                }
            }
        }
        cout << res << '\n';
    }  
}