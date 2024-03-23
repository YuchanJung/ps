#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 1001

using namespace std;

int map[MAX][MAX] = {0};
char s1[MAX];
char s2[MAX];
vector<char> v;

void LCS(int i, int j) {
    if (i == 0 || j == 0) return;
    if (s1[i - 1] == s2[j - 1]) {
        v.push_back(s1[i - 1]);
        LCS(i - 1, j - 1);
    }
    if (map[i - 1][j] > map[i][j - 1]) LCS(i - 1, j);
    else LCS(i, j - 1);
}

int main() {
    scanf("%s", s1);
    scanf("%s", s2);
    int n = strlen(s1);
    int m = strlen(s2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                map[i][j] = map[i - 1][j - 1] + 1;
            }
            else {
                map[i][j] = max(map[i - 1][j], map[i][j - 1]);
            }
        }
    }
    int cnt = map[n][m];
    printf("%d\n", cnt);

    int i = n; int j = m;
    while (cnt > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            v.push_back(s1[i - 1]);
            i -= 1;
            j -= 1;
            cnt--;
        }
        else if (map[i - 1][j] > map[i][j - 1]) i -= 1;
        else j -= 1;
    }
    // LCS(n, m);
    cnt = map[n][m];
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%c", v[i]);
    }
}