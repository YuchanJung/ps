// 2차원 벡터 사용
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Mat = vector<vector<int>>;

ll n, b;

Mat mul(Mat a, Mat b) {
    Mat r(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                r[i][j] = (r[i][j] + a[i][k] * b[k][j]) % 1000;
    return r;
}

Mat pow(Mat a, ll b) {
    Mat r(n, vector<int>(n));
    for (int i = 0; i < n; i++) r[i][i] = 1;

    while (b > 0) {
        if (b % 2) r = mul(r, a);
        b /= 2;
        a = mul(a, a);
    }
    return r;
}

int main() {
    cin >> n >> b;
    Mat v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    Mat r = pow(v, b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << r[i][j] << ' ';
        }
        cout << '\n';
    }
}

// 2차원 배열 사용
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, b;

int** init() {
    int** r = new int*[n];
    for(int i = 0; i < n; i++)
        r[i] = new int[n];
    return r;
}

int** mul(int **a, int **b) {
    int** p = init();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                p[i][j] += (a[i][k] * b[k][j] % 1000);
                p[i][j] %= 1000;
            }
        }
    }
    return p;
}

int** pow(int **a, ll b) {
    int** res = init();
    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }
    
    int **temp = a;
    while (b > 0) {
        if (b % 2) res = mul(res, temp);
        b /= 2;
        temp = mul(temp, temp);
    }
    return res;
}

int main() {
    cin >> n >> b;
    int** mat = init();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int **newmat = pow(mat, b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << newmat[i][j] << ' ';
        }
        cout << '\n';
    }
}
