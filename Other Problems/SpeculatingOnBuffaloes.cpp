#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int n;
int memo[100000000];
int a[100000000];

//Recursive solution with memoization
int solve(int i) {
    if (i >= (n - 1)) {
        return 0;
    }
    if (memo[i] != -1) {
        return memo[i];
    }

    memo[i] = solve(i + 1);
    range(j, i + 1, n) {
        memo[i] = max(memo[i], solve(j + 1) - a[i] + a[j] - 4);
    }
    return memo[i];
}

int main() {
    cin >> n;
    range(i, 0, n) {
        cin >> a[i];
    }

    range(i, 0, n) {
        memo[i] = -1;
    }
    println("Recursive: %d", solve(0));

    //Dynamic Programming Solution
    int dp[n];
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = max(dp[i + 1], a[n - 1] - a[i] - 4);
        range(j, i + 1, n - 1) {
            dp[i] = max(dp[i], dp[j + 1] - a[i] + a[j] - 4);
        }
    }
    println("Dynamic Programming: %d", dp[0]);
}
