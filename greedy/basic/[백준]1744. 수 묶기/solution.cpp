#include <bits/stdc++.h>
using namespace std;

int n, k, z, res;
priority_queue<int> ppq, npq;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k > 0) ppq.push(k);
        else if (k < 0) npq.push(-k);
        else z++;
    }
    while (ppq.size() > 1) {
        int n1 = ppq.top(); ppq.pop();
        int n2 = ppq.top();
        if (n1 + n2 < n1 * n2) {
            res += n1 * n2;
            ppq.pop();
        }
        else res += n1;
    }
    if (!ppq.empty()) res += ppq.top();
    while (npq.size() > 1) {
        int s = -npq.top(); npq.pop();
        s *= -npq.top(); npq.pop();
        res += s;
    }
    if (!npq.empty() && z == 0) res += -npq.top();
    cout << res;
}