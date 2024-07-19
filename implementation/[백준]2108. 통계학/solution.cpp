#include <bits/stdc++.h>

using namespace std;

int n, x;
int sum, median, mode_cnt, mode_id, mode, _min, _max;
int arr[8001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i == 0) _min = _max = x;
        sum += x;
        int idx = 4000 + x;
        arr[idx] += 1;
        if (arr[idx] > mode_cnt) mode_cnt = arr[idx];
        if (_min > x) _min = x;
        if (_max < x) _max = x;
    }

    int c = 0;
    int target = n / 2 + 1;
    for (int i = 0; i < 8001; i++) {
        if (arr[i] == mode_cnt && mode_id < 2) {
            mode = i - 4000;
            mode_id++;
        }
    }
    for (int i = 0; i < 8001; i++) {
        if (c + arr[i] < target) c += arr[i];
        else {
            median = i - 4000;
            break;
        }
    }
    int mean = round(sum * 1.0 / n);
    if (mean == -0) mean = 0;
    cout << mean << '\n' << median << '\n' << mode << '\n' << _max - _min;
}