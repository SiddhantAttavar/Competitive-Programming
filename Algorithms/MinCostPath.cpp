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
    input(int, m);
    int cost[n][m];
    range(i, 0, n) {
        range(j, 0, n) {
            cin >> cost[i][j];
        }
    }

    range(i, 1, n) {
        cost[i][0] += cost[i - 1][0];
    }

    range(j, 1, m) {
        cost[0][j] += cost[0][j - 1];
    }

    range(i, 1, n) {
        range(j, 1, m) {
            cost[i][j] += min(cost[i - 1][j - 1], min(cost[i - 1][j], cost[i][j - 1]));
        }
    }

    print(cost[n - 1][m - 1]);
}