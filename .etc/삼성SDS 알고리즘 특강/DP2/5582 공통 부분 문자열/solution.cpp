#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 4001

using namespace std;
int map[MAX][MAX] = {0};
char s1[MAX];
char s2[MAX];
int res = 0;

int main() {
    scanf("%s", s1);
    scanf("%s", s2);
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    for (int i = 0; i < s1_len; i++) {
        for (int j = 0; j < s2_len; j++) {
            if (s1[i] == s2[j]) {
                if (i == 0 || j == 0) map[i][j] = 1;
                else map[i][j] = map[i - 1][j - 1] + 1;
                res = max(res, map[i][j]);
            }
        }
    }
    printf("%d", res);
}