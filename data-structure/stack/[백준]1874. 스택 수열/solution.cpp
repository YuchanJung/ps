#include <bits/stdc++.h>

using namespace std;

int n, x, k = 1;
vector<char> v;
stack<int> s;

int main() {
    cin >> n;
    s.push(0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (s.top() == x) {
            s.pop();
            v.push_back('-');
        }
        else if (s.top() < x) {
            while (s.top() < x) {
                v.push_back('+');
                s.push(k++);
            }
            s.pop();
            v.push_back('-');
        }
        else {
            cout << "NO";
            return 0;
        }
    }

    for (auto &c: v) cout << c << '\n';
}