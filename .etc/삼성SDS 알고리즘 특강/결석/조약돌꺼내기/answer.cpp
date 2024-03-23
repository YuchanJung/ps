#include <cstdio>

#define MAX (50+3)

using namespace std;

int M, K;

double Ccnt[MAX];
double percent[MAX];

double total, ans;
int cnt;

int main() {
    scanf("%d", &M);

    int input;
    for (int i = 0; i < M; i++) {
        scanf("%d", &input);
        Ccnt[i] = (double)input;
        total += Ccnt[i]; //돌의 총 갯수 
    }

    scanf("%d", &K);
    double tmp;
    //각 색깔별로 뽑을 확률을 저장 
    for (int i = 0; i < M; i++) {

        if (Ccnt[i] < K) continue;

        tmp = 1.0;
        for (int j = 0; j < K; j++) {

            tmp *= (Ccnt[i] - j) / (total - j);
        }
        percent[i] = tmp;
    }

    //색깔별 확률 합산 
    for (int i = 0; i < M; i++) {
        ans += percent[i];
    }

    printf("%.11lf", ans);
    return 0;
}