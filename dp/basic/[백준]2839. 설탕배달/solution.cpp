// greedy
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    while (n > 0) {
        if (n % 5 == 0) {
            cnt += n / 5;
            break;
        }
        n -= 3;
        cnt++;
    }
    if (n < 0) cout << -1;
    else cout << cnt;
}


// dp
#include <bits/stdc++.h>

using namespace std;

int n;
int arr[5001];

int main() {
    cin >> n;
    arr[1] = arr[2] = arr[4] = -1;
    arr[3] = arr[5] = 1;
    for (int i = 6; i <= 5000; i++) {
        if (arr[i - 3] == -1 && arr[i - 5] == -1) arr[i] = -1;
        else if (arr[i - 3] == -1) arr[i] = arr[i - 5] + 1;
        else if (arr[i - 5] == -1) arr[i] = arr[i - 3] + 1;
        else arr[i] = min(arr[i - 3], arr[i - 5]) + 1;
    }
    cout << arr[n];
}