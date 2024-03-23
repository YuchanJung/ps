#include <cstdio>
#include <algorithm>
#define MAX 1000

using namespace std;
int n, m;
int arr[MAX + 1][MAX + 1] = {0};
int res = 0;

int main() {
    char s[MAX + 1];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        for (int j = 1; j <= m; j++) {
            arr[i][j] = s[j - 1] - '0';
            if (arr[i][j] == 1) {
                arr[i][j] = min(arr[i][j - 1], min(arr[i - 1][j], arr[i - 1][j - 1])) + 1;
                res = max(res , arr[i][j] * arr[i][j]);
            }  
        }
    }
    printf("%d", res);
}