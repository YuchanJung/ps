#include <bits/stdc++.h>
using namespace std;

int n, x;
priority_queue<int> pq_neg;
priority_queue<int, vector<int>, greater<int>> pq_pos;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != 0) {
            if (x > 0) pq_pos.push(x);
            else pq_neg.push(x);
            continue;
        }
        bool neg_empt = pq_neg.empty();
        bool pos_empt = pq_pos.empty();
        if (neg_empt && pos_empt) {
            cout << 0 << '\n';
            continue;
        }
        bool n = false, p = false;

        if (!neg_empt && pos_empt) n = true;
        else if (neg_empt && !pos_empt) p = true;
        else if (pq_pos.top() >= -pq_neg.top()) n = true;
        else p = true;

        if (n) {
            cout << pq_neg.top() << '\n';
            pq_neg.pop();
        }
        if (p) {
            cout << pq_pos.top() << '\n';
            pq_pos.pop();
        }       
    }
}