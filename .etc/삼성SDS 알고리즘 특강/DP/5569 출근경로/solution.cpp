#include <cstdio>
#define MAX 100

using namespace std;
int w, h;
int map[MAX + 1][MAX + 1][2] = {0}; // 왼 , 아래

int main() {
    scanf("%d %d", &w, &h);

    for (int i = 1; i <= w; i++) {
        map[1][i][1] = 1;
    }
    for (int i = 1; i <= h; i++) {
        map[i][1][0] = 1;
    }

    for (int i = 2; i <= w; i++) {
        for (int j = 2; j <= h; j++) {
            
        }
    }
}