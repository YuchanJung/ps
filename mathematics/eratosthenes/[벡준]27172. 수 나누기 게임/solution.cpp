#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001];
int res[100001];
int idx[1000001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        idx[arr[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        int t = arr[i];
        for (int j = 1; j <= sqrt(t); j++) {
            if (t % j == 0) {
                if (idx[j]) {
                    res[idx[j]] += 1;
                    res[i] -= 1;
                }
                if (t / j != j && idx[t / j]) {
                    res[idx[t / j]] += 1;
                    res[i] -= 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
}

/*
//에라토스테네스의 채
for(int i = 1; i <= n; i++) {
    int t = arr[i];
    for(int j = t * 2; j < 1000001; j += num) {
        if (idx[j]) {
            res[i]++;
            res[idx[j]]--;
        }
    }
}
*/
