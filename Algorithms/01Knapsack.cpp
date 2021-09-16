#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int main() {
    //Input
    input(int, n);
    input(int, k);
    int w[n], v[n];
    range(i, 0, n) {
        cin >> w[i];
        cin >> v[i];
    }

    //0 - 1 Knapsack
    int dp[n][k + 1];
    dp[0][0] = 0;
    range(i, 1, k + 1) {
        if (i >= w[0]) {
            dp[0][i] = v[0];
        }
        else {
            dp[0][i] = 0;
        }
    }

    range(i, 1, n) {
        range(j, 0, w[i]) {
            dp[i][j] = dp[i - 1][j];
        }
        range(j, w[i], k + 1) {
            dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
        }
    }

    print(dp[n - 1][k]);
}