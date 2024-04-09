#include <bits/stdc++.h>

using namespace std;

stack<int> st;
string s;
int ans = 0;

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(-1);
        else if (s[i] == '[') st.push(-2);

        else if (s[i] == ')') {
            int temp = 0;
            while (!st.empty() && st.top() != -1) {
                temp += st.top();
                st.pop();
            }
            if (st.empty() || temp < 0) break;

            st.pop();
            if (temp == 0) temp++;
            st.push(temp * 2);
        }
        else { // s[i] == ']'
            int temp = 0;
            while (!st.empty() && st.top() != -2) {
                temp += st.top();
                st.pop();
            }
            if (st.empty() || temp < 0) break;
            
            st.pop();
            if (temp == 0) temp++;
            st.push(temp * 3);
        }
    }

    while (!st.empty()) {
        if (st.top() == -1 || st.top() == -2) {
            ans = 0;
            break;
        }
        else {
            ans += st.top();
            st.pop();
        }
    }

    cout << ans;
}