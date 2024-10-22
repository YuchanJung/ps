#include <bits/stdc++.h>

using namespace std;
using pq = priority_queue<long>;

long t, k, n;
char cmd;
pq p1, p2;
unordered_map<long, long> um;

void init() {
    while (!p1.empty()) p1.pop();
    while (!p2.empty()) p2.pop();
    um.clear();
}
void sync(pq *p, long n) {
    while(!p->empty() && um.find(p->top() * n) == um.end()) p->pop();
}
void _insert(long n) {
    p1.push(n);
    p2.push(-n);
    if (um.find(n) != um.end()) um[n]++;
    else um[n] = 1;
}
void _delete(long n) {
    pq *p;
    p = (n == 1) ? &p1 : &p2;
    sync(p, n);
    if (p->empty()) return;
    
    long k = p->top() * n; p->pop();
    um[k] -= 1;
    if (um[k] == 0) um.erase(k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        init();
        cin >> k;
        while (k--) {
            cin >> cmd >> n;
            if (cmd == 'I') _insert(n);
            else _delete(n);
        }
        sync(&p1, 1);
        sync(&p2, -1);
        if (p1.empty() || p2.empty()) cout << "EMPTY" << '\n';
        else cout << p1.top() << ' ' << -p2.top() << '\n';
    }
}