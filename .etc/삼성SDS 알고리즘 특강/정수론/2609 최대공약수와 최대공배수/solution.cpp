#include <iostream>

using namespace std;

int leftGcd;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {

}