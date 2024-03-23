#include <cstdio>
#include <vector>

using namespace std;
int N;
int arr[1001];
int dp[1001][2];
int _max = 0, start = 0;
vector<int> path;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        dp[i][0] = 1;
        dp[i][1] = i;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = i - 1; j >= 1; j--) {
            if (arr[j] < arr[i]) {
                if (dp[i][0] < dp[j][0] + 1) {
                    dp[i][0] = dp[j][0] + 1;
                    dp[i][1] = j;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (_max < dp[i][0]) {
            _max = dp[i][0];
            start = i;
        }
    }

    printf("%d\n", _max);
    for (int i = 0; i < _max; i++) {
        path.push_back(arr[start]);
        start = dp[start][1];
    }

    for (int i = _max - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
}