#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

vector<int> adj[9];
int dp[9][2];
int d;

void connect(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int main() {
    int e[12][2] = {
        {1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5},
        {4, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 8}, {7, 8} 
    };
    for (int i = 0; i < 12; i++) connect(e[i][0], e[i][1]);

    cin >> d;
    dp[2][0] = dp[3][0] = 1;
    d -= 1;
    while (d--) {
        for (int i = 1; i <= 8; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                int next = adj[i][j];
                dp[next][1] = (dp[next][1] + dp[i][0]) % MOD;
            }
        }

        for (int i = 1; i <= 8; i++) {
            dp[i][0] = dp[i][1];
            dp[i][1] = 0;
        }
    }
    cout << dp[1][0];
}