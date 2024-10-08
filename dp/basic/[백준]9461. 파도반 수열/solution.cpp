#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T, N;
    long long arr[101]= {0, 1, 1, 1, 2};
    for (int i = 5; i <= 100; i++) {
        arr[i] = arr[i - 1] + arr[i - 5];
    }
    cin >> T;
    while (T--) {
        cin >> N;
        cout << arr[N] << '\n';
    }
}