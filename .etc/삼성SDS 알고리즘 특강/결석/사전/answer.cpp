#include <cstdio>
#define MAXK 1000000000
int N,M;
long long K;
long long dp[201][101];
char ans[201];
int main() 
{
    scanf("%d %d %lld",&N,&M,&K);

    // 파스칼의 삼각형 구하기 
    dp[0][0] = 1;
    for(int i = 1 ; i <= N+M ; i++) 
    {
        dp[i][0] = 1;
        for(int j = 1 ; j <= M ; j++) 
        {
            //nCk의 값이 어느 순간 long의 범위를 넘어버릴 수 있으므로 유의 한다.
            //따라서 K의 최대값보다 커지는 경우 MAXK+1로 저장 한다 
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            if(dp[i][j] > MAXK) dp[i][j] = MAXK+1;
        }
    }

    int L = M+N; //전체 문자열의 길이 : m+n
    if(dp[L][M] < K) printf("-1"); //만약 K번째가 전체 문자열의 개수보다 클경우 -1로 처리 
    else{
        int i,m = M, n = N; // a의 수 n, z의 수 m  
        //전체 문자열의 길이 T에 대해서 앞에 문자부터 확정해 나간다.
        for(i = 0 ; i < L ; i++)
        {
            if(dp[L-i-1][m] < K) //현재 위치에 'a'문자가 오는 가지수(nCk[L-i-1][m]) 보다 큰 경우 -> z
            {
                ans[i]='z';
                K -= dp[L-i-1][m]; //찾고자 하는 K번째를 조정한다. 
                m--; //'z'를 하나 선택했으므로 하나 줄여준다.
            }
            else //현재 위치에 'a'문자가 오는 가지수(nCk[T][M]) 보다 작거나 같은 경우 -> a
            {
                ans[i]='a';
            }
        }
        ans[N+M] = 0;
        printf("%s",ans);
    }
}