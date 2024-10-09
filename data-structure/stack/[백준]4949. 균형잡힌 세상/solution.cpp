#include <bits/stdc++.h>

using namespace std;

string s;
stack<char> st;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    st.push('0');
    while (true) {
        getline(cin, s);
        if (s == ".") break;

        for (auto &c: s) {
            if (c == '(' || c == '[')
                st.push(c);
            if (c == ']') {
                if (st.top() == '[') st.pop();
                else st.push(c);
            }
            if (c == ')') {
                if (st.top() == '(') st.pop();
                else st.push(c);
            }
        }

        if (st.size() == 1) cout << "yes\n";
        else cout << "no\n";

        while (!st.empty()) st.pop();
        st.push('0');
    }
}