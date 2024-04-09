#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int n, x, y, d, g, res;
int arr[101][101];

int main() {
    cin >> n;
    while(n--) {
        cin >> y >> x >> d >> g;
        vector<int> v = {d};
        for (int i = 0; i < g; i++) {
            for (int j = v.size() - 1; j >= 0; j--) {
                v.push_back((v[j] + 1) % 4);
            }
        } 
        
        arr[x][y] = 1;
        for (auto &c : v) {
            x += dx[c];
            y += dy[c];
            arr[x][y] = 1;
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1]) res++;
        }
    }
    cout << res;
}