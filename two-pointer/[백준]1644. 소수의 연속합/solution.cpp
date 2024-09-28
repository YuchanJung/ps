#include <bits/stdc++.h>
#define MAX 4000000
using namespace std;

int n, res;
int arr[MAX + 1];
int l, r = 1;
vector<int> p = {0};

int main() {
    for (int i = 2; i <= MAX; i++) arr[i] = 1;
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (arr[i] == 0) continue;
        for (int j = i * 2; j <= MAX; j += i) {
            arr[j] = 0;
        }
    }

    for (int i = 2; i <= MAX; i++) {
        if (arr[i] == 1) {
            p.push_back(i + p[p.size() - 1]);
        }
    }
    
    cin >> n;
    while (l < r) {
        int x = p[r] - p[l];
        if (x == n) {
            res++;
            r++;
        }
        else if (x > n) {
            l++;
        }
        else {
            r++;
        }
    }
    cout << res;
}