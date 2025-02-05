#include <bits/stdc++.h>
using namespace std;

int n;
bool isPrime(int k) {
    if (k == 1) return false;
    for (int i = 2; i <= sqrt(k); i++) {
        if (k % i == 0) return false;
    }
    return true;
}

void dfs(int k) {
    if (k > pow(10, n - 1)) {
        cout << k << '\n';
        return;
    }

    for (int i = 1; i <= 9; i++) {
        int next = k * 10 + i;
        if (isPrime(next))
            dfs(next);
    }
}

int main() {
    cin >> n;
    for (int i = 2; i <= 9; i++) {
        if (isPrime(i))
            dfs(i);
    }
}