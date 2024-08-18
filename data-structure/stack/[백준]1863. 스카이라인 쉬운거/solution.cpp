#include <bits/stdc++.h>

using namespace std;

int n, res;
int x, y;
stack<int> st;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        while (!st.empty() && y < st.top()) {
            st.pop();
            res++;
        }
        if (st.empty() || (!st.empty() && y > st.top())) {
            if (y != 0) st.push(y);
        }
    }
    res += st.size();
    cout << res;
}


/*
#include <bits/stdc++.h>

using namespace std;

int n, res;
int x, y;
vector<int> st;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        while (!st.empty() && st.back() > y) {
            st.pop_back();
        }
        if (st.empty() || (!st.empty() && st.back() < y)) {
            if (y != 0) {
                st.push_back(y);
                res++;
            }
        }
    }
    cout << res;
}
*/