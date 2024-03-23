#include <cstdio>
#define MAX 100000

using namespace std;

int N, M, a, b;
int arr[MAX + 1];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        if (i != 0) arr[i] += arr[i - 1];
    }

    for (int i = 0; i < M; i++) {
        int res;
        scanf("%d %d", &a, &b);
        if (a == 1) res = arr[b - 1];
        else res = arr[b - 1] - arr[a - 2];
        printf("%d\n", res);
    }
}