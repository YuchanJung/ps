#include <cstdio>
#define MAX 1024

using namespace std;
int N, M;
int arr[MAX + 1][MAX + 1] = {0};
int x1, y1, x2, y2;

void print_list() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
            arr[i][j] += arr[i][j - 1];
            arr[i][j] += arr[i - 1][j];
            arr[i][j] -= arr[i - 1][j - 1];
        }
    }
    // print_list();

    for (int i = 0; i < M; i++) {
        int res;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        res = arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
        printf("%d\n", res);
    }
}