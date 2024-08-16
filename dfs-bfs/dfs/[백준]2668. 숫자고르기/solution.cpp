#include <bits/stdc++.h>

using namespace std;

int n;
int arr[101];
bool visited[101];
vector<int> v;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        visited[i] = true; 
        int s = arr[i];
        while (true) {
            if (visited[s]) break;
            visited[s] = true;
            s = arr[s];
        }
        if (i == s) v.push_back(i);
    }
    cout << v.size() << '\n';
    for (auto &s: v) cout << s << '\n';
}