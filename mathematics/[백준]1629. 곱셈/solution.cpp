#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        exp /= 2;
        base = (base * base) % mod;
    }
    return res;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c);
}