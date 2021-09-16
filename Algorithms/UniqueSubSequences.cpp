#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int main() {
    input(int, n);
    input(int, k);
    arrput(int, a, n);

    int dp[n][k];
    range(i, 0, n) {
        dp[0][i] = 1;
        printf("%d ", dp[0][i]);
    }
    println("");

    range(i, 1, k) {
        unordered_map<int, int> prev;
        range(j, 0, i) {
            dp[i][j] = 0;
        }
        range(j, i, n) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            if (prev.find(a[j]) != prev.end()) {
                dp[i][j] -= prev.at(a[j]);
            }
            prev.emplace(a[j], dp[i][j]);
        }
    }

    range(i, 0, k) {
        range(j, 0, n) {
            printf("%d ", dp[i][j]);
        }
        println("");
    }

    print(dp[k - 1][n - 1]);
}