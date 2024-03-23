#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define NMAX 75000 // 섬의 개수 N (1 ≤ n ≤ 75000)
typedef pair<int, int> P;

int treesize, start;
long tree[NMAX*4];

// a번 값을 1 증가시키는 함수
void update(int idx, int value) {
    idx = idx + start;
    tree[idx] += value;
    for (int p = idx / 2; p > 0; p = p / 2) {
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
}

// 구간 [a, b)의 값의 개수를 세는 함수
long get(int left, int right) {
    long sum = 0;
    left = left + start;
    right = right + start;

    while (left <= right) {
        if (left % 2 == 1) {
            sum = sum + tree[left];
            left = left + 1;
        }
        if (right % 2 == 0) {
            sum = sum + tree[right];
            right = right - 1;
        }

        left = left / 2;
        right = right / 2;
    }
    return sum;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++) {
        int N;
        scanf("%d", &N);
        P point[NMAX];
        for(int i=0; i<N; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            point[i] = P(y, x);
        }

        // 점들을 y좌표 기준으로 정렬한 후, 각 y좌표마다 새 값을 매김
        int range = 0;
        int tempY[75000];
        sort(point, point+N);
        for(int i=0; i<N; i++) {
            if(i>0 && point[i].first != point[i-1].first) range++;
            tempY[i] = range;
        }
        // 점들을 다시 x좌표가 감소하는 기준으로 정렬
        for(int i=0; i<N; i++) {
            point[i].first = -point[i].second;
            point[i].second = tempY[i];
        }
        sort(point, point+N);

        treesize = range+1;
        start = 1;
        while(start < treesize) start *= 2;
        memset(tree, 0, sizeof(tree));

        long ans = 0;
        // X가 큰 것 부터 내려오면서 
        for( int i = 0; i < N; i++){
            int y = point[i].second;
            //Y축이 더 작은것 부분합(0 ~ Y까지) result에 더하기
            ans += get(0 , y);

            // 현재 Value를 해당 Y 위치에 인덱스트리 추가
            // 인덱스 트리 추가한 것 부분합 업데이트
            update(y, 1);
        }

        printf("%ld\n", ans);
    }
}