#include <bits/stdc++.h>
using namespace std;

int p, s, a, c, g, t, res;
string dna;
int cnt[4];

void update(int i, int d) {
    if (dna[i] == 'A')
        (d > 0) ? cnt[0]++ : cnt[0]--;
    else if (dna[i] == 'C')
        (d > 0) ? cnt[1]++ : cnt[1]--;
    else if (dna[i] == 'G')
        (d > 0) ? cnt[2]++ : cnt[2]--;
    else 
        (d > 0) ? cnt[3]++ : cnt[3]--;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s >> p >> dna;
    cin >> a >> c >> g >> t;

    int k = p - 1;

    for (int i = 0; i <= k; i++) {
        update(i, 1);
    }
    
    while (true) {
        if (cnt[0] >= a && cnt[1] >= c && cnt[2] >= g && cnt[3] >= t) res++;

        if (k == s - 1) break;
        update(++k, 1);
        update(k - p, -1);
    }
    cout << res;
}