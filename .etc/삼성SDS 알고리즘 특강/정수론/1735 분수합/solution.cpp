#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
} 

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int a, b, c, d;

int main () {
    cin >> a >> b >> c >> d; 
    a = a * d;
    c = c * b;
    // a + c \ b * d
    int g = gcd(a + c, b * d);
    cout << (a + c) / g << ' ' << (b * d) / g;
}