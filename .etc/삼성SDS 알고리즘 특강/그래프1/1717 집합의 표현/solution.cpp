#include <cstdio>
#define MAX 1000000

using namespace std;
int n, m;
int parent[MAX + 1];
int prank[MAX + 1]; // 최적화
int x, a, b;

void init() {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        prank[i] = 1;
    }
}

int getParent(int a) {
    if (parent[a] == a) return a;
    // else return getParent(parent[a]);
    else return parent[a] = getParent(parent[a]); // 최적화
}

bool find(int a, int b) {
    int x = getParent(a);
    int y = getParent(b);
    return x == y;
}

void _union(int a, int b) {
    int x = getParent(a);
    int y = getParent(b);
    
    if (x < y) {
        parent[y] = parent[x];
    }
    else {
        parent[x] = parent[y];
    }
    

    // 최적화
    /*
    if (x == y) return;
    */
}


int main() {
    scanf("%d %d", &n, &m);
    init();
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &a, &b);
        if (x == 0) {
            _union(a, b);
        }
        else {
            if (find(a, b)) printf("YES\n");
            else printf("NO\n");
        }
    }
}