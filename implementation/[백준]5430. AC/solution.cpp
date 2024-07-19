#include <bits/stdc++.h>

using namespace std;

int T, n;
string p, xs;

void init(deque<int> &dq, string xs) {
    int idx = 1;
    string temp = "";
    while (idx < xs.length() - 1) {
        if (xs[idx] != ',') temp += xs[idx];
        else {
            dq.push_back(stoi(temp));
            temp = "";
        }
        idx++;
    }
    if (temp.length() > 0) dq.push_back(stoi(temp));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> p >> n >> xs;
        deque<int> dq;
        init(dq, xs);
        bool hasError = false;
        bool isFront = true; 
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') isFront = !isFront;
            else {
                if (dq.empty()) {
                    hasError = true;
                    break;
                }
                else {
                    if (isFront) dq.pop_front();
                    else dq.pop_back();
                }
            }
        }

        if (hasError) cout << "error\n";
        else {
            cout << "[";
            if (isFront) {
                while (!dq.empty()) {
                    cout << dq.front();
                    dq.pop_front();
                    if (!dq.empty()) cout << ',';
                }
            }
            else {
                while(!dq.empty()) {
                    cout << dq.back();
                    dq.pop_back();
                    if (!dq.empty()) cout << ',';
                }
            }
            cout << "]\n";
        }
    }
}