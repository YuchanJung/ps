#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>

#define NMAX 1000000
int N, input[NMAX+1], DP[NMAX+1][2], ans[NMAX+1];
int tree[NMAX*3][2], start;
int ret_value, ret_index;

int prev[NMAX+1];

int comp(const void * arg1, const void * arg2){
    int * a = (int*)arg1;
    int * b = (int*)arg2;
    if(a[0] != b[0]) return a[0] - b[0];
    else return b[1] - a[1]; // 값이 같은 경우 인덱스가 큰 값부터 처리 
}

void update(int idx, int value) {
    idx = idx + start;
    tree[idx][0] = value;
    tree[idx][1] = idx;
    for (int p = idx / 2; p > 0; p = p / 2) {
        if(tree[p * 2][0] > tree[p * 2 + 1][0]){
            tree[p][0] = tree[p * 2][0];
            tree[p][1] = tree[p * 2][1];            
        }else{
            tree[p][0] = tree[p * 2 + 1][0];
            tree[p][1] = tree[p * 2 + 1][1];    
        }
    }
}

void get(int left, int right) {
    ret_value = 0;
    ret_index = 1;

    while (left <= right) {
        if (left % 2 == 1) {
            if(tree[left][0] > ret_value){
                ret_value = tree[left][0];
                ret_index = tree[left][1];
            }
            left = left + 1;
        }
        if (right % 2 == 0) {
            if(tree[right][0] > ret_value){
                ret_value = tree[right][0];
                ret_index = tree[right][1];
            }
            right = right - 1;
        }

        left = left / 2;
        right = right / 2;
    }
}

int main()
{
    scanf("%d",&N);

    // 인덱스 트리 초기화 
    for(int i = 0 ; i < N*3 ; i++) tree[i][0] = 0;
    start = 1;
    while(start<N) start*=2;

    for(int i = 0 ; i < N ; i++){
        scanf("%d",&input[i]);
        DP[i][0] = input[i]; // 값 
        DP[i][1] = i; // 인덱스 
    }

    // 값 기준으로 오름차순 정렬 
    qsort(DP,N,sizeof(int)*2,comp);

    // 값이 작은 인덱스부터 처리 
    for(int i = 0 ; i < N ; i++){
        // 현재 인덱스보다 앞에 있는 값 중 가장 LIS 값이 큰 값과 인덱스를 구해온다. 
        get(0+start,DP[i][1]+start-1);
        // 현재 인덱스 앞에 연결된 LIS 인덱스 갱신 
        prev[DP[i][1]] = ret_index-start;
        // 현재 인덱스까지 사용해서 만들 수 있는 LIS값 갱신 : maxCnt+1
        update(DP[i][1],ret_value+1);
    }

    printf("%d\n",tree[1][0]); // 가장 긴 LIS 길이 값 출력 

    int cur = tree[1][1]-start; // 가장 긴 LIS 길이 값을 만드는 마지막 인덱스

    for(int i = tree[1][0]-1 ; i >= 0 ; i--){
        ans[i] = input[cur];
        cur = prev[cur];
    }
    for(int i=0;i<tree[1][0];i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}