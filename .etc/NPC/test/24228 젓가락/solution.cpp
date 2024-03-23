#include <cstdio>

using namespace std;

long long n, r;

int main() {
    scanf("%lld %lld", &n, &r);
    printf("%lld",  n + 1 + 2 * (r - 1));
}