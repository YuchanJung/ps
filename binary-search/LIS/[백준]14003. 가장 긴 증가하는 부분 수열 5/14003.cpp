// new version
#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

int n, x, r;
int arr[1000001], pre[1000001];
vector<int> v = {-INF};
vector<int> res;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    for (int i = 1; i <= n ; i++) {
        int k = arr[i];
        int u = lower_bound(v.begin(), v.end(), k) - v.begin();
        if (u == v.size()) {
            pre[i] = v.back();
            v.push_back(k);
        }
        else {
            pre[i] = v[u - 1];
            v[u] = k;
        }
    }

    r = v.size() - 1;
    int k = v[r];
    for (int i = n; i >= 1; i--) {
        if (arr[i] == k) {
            res.push_back(k);
            k = pre[i];
        }
    }
    cout << r << '\n';
    for (int i = r - 1; i >= 0; i--)
        cout << res[i] << ' ';
}

// old version
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, i;
    cin >> n;
    int arr[1000000];
    vector<int> record;
    vector<int> length;
    vector<int> res_arr;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    record.push_back(arr[0]);
    length.push_back(1);
    for (i = 1 ; i < n; i++) {
        if (arr[i] > record.back()) {
            record.push_back(arr[i]);
            length.push_back(record.size());
        }
        else {
            int start = 0;
            int end = record.size() - 1;
            while (start < end) {
                int mid = (start + end) / 2;
                if (arr[i] > record[mid]) {
                    start = mid + 1;
                }
                else {
                    end = mid;
                }
            }
            record[end] = arr[i];
            length.push_back(end + 1);
        }
    }
    int res = record.size();
    cout << res << endl;
    for (i = n - 1; i >= 0; i--) {
        if (length[i] == res) {
            res_arr.push_back(arr[i]);
            res--;
        }
    }
    for (i = res_arr.size() - 1; i >= 0; i--) {
        cout << res_arr[i] << ' ';
    }
    cout << endl;
}