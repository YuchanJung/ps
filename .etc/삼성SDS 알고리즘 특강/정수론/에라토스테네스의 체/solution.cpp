#include <iostream>
#include <cstdio>
#include <string.h>
#define MAX 1000

using namespace std;

bool primeNum[MAX + 1];
int N, K;


int main() {
    cin >> N >> K;
    memset(primeNum, true, sizeof(primeNum));

    primeNum[0] = primeNum[1] = false;
    for (int i = 2; i <= N; i++) {
        if (primeNum[i]) {
            for (int j = i; j <= N; j+= i) {
                if (!primeNum[j])  continue;
                primeNum[j] = false;
                K--;
                if (K == 0) {
                    cout << j;
                    break;
                }
            }
        }
    }
}