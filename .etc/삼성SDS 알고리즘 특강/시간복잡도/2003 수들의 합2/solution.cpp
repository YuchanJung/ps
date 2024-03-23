#include <iostream>

using namespace std;

int main() {
    int N, M;
    int arr[10001] = {0};
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    
    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] - arr[j] == M) res++;
        }
    }

    cout << res;

    return 0;
}