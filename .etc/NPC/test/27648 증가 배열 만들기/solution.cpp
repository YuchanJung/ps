#include <cstdio>

using namespace std;

int n, m, k;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    if (n + m - 1 <= k) {
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", i + j);
            }
            printf("\n");
        }
    }
    else {
        printf("NO\n");
    }
}