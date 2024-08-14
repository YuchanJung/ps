#include <bits/stdc++.h>

using namespace std;

int arr[500000], res[500000];
int n;
vector<vector<int>> st;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.back()[0] < arr[i]) {
            res[st.back()[1]] = i + 1;
            st.pop_back();
        }
        st.push_back({arr[i], i});
    }
    for (int i = 0; i < n; i++) cout << res[i] << ' ';
}