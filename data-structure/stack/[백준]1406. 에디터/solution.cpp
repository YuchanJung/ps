#include <bits/stdc++.h>

using namespace std;

string s, cmd;
stack<char> l, r;
deque<char> dq;
int m;

int main() {
    cin >> s >> m;
    cin.ignore();

    for (auto &c: s)
        l.push(c);

    while (m--) {
        getline(cin, cmd);
        if (cmd[0] == 'L') {
            if (l.empty()) continue;
            r.push(l.top());
            l.pop();
        }
        else if (cmd[0] == 'D') {
            if (r.empty()) continue;
            l.push(r.top());
            r.pop();
        }
        else if (cmd[0] == 'B') {
            if (l.empty()) continue;
            l.pop();
        }
        else {
            l.push(cmd[2]);
        }
    }

    while (!l.empty()) {
        r.push(l.top());
        l.pop();
    }

    while (!r.empty()) {
        cout << r.top();
        r.pop();
    }

    // while (!r.empty()) {
    //     dq.push_back(r.top());
    //     r.pop();
    // }
    // while (!l.empty()) {
    //     dq.push_front(l.top());
    //     l.pop();
    // }
    
    // while (!dq.empty()) {
    //     cout << dq.front();
    //     dq.pop_front();
    // }
}