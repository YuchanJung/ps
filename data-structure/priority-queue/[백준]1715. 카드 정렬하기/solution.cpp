#include <bits/stdc++.h>

using namespace std;

int n, x, res;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }
    while (!pq.empty()) {
        int n1 = pq.top(); pq.pop();
        if (pq.empty()) break;
        
        int n2 = pq.top(); pq.pop();
        res += n1 + n2;
        pq.push(n1 + n2);
    }
    cout << res;
}