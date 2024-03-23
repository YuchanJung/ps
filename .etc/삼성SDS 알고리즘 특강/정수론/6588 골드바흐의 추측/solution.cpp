#include <iostream>
#include <cstdio>
#include <string.h>
#define MAX 1000000

using namespace std;

bool primeNum[MAX + 1];
int N, K;

void get_primeNum() {
    primeNum[0] = primeNum[1] = false;
    for (int i = 2; i <= MAX; i++) {
        if (primeNum[i]) {
            for (int j = i + i; j <= MAX; j+= i) {
                primeNum[j] = false;
            }
        }
    }
}


int main() {
    
    memset(primeNum, true, sizeof(primeNum));

    get_primeNum();
    
    int flag = true;
    int n = 1;
    while (n > 0) {
        cin >> n;
    }

    for (int i = 3; i <= n; i+= 2) {
        if (primeNum[i] && primeNum[n - i]) {
            printf("%d = %d + %d\n", n, i, n - i);
            flag = false;
            break;
        }
    }

    if (flag) 
        printf("Goldbach's conjecture is wrong.");
    
}