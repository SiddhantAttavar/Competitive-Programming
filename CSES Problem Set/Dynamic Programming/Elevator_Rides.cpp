#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
array<int,2> dp[1 << 20];
int main() {
	int n, x; cin >> n >> x;
    int weight[n]; arrPut(weight);

    // dp[i][0] = the minimum number of rides for bitmask i
    // dp[i][1] = the minimum weight of the last ride for bitmask i
    dp[0] = {0, 0};
    for (int i = 1; i < (1 << n); i++) {
        // upper bound is n + 1 rides
        dp[i] = {n + 1, 0};
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                auto cur = dp[i ^ (1 << j)];
                if (cur[1] + weight[j] <= x) { // add j to the current ride
                    cur[1] += weight[j];
                }
                else { // reserves a new ride for j
                    cur[0]++;
                    cur[1] = weight[j];
                }
                dp[i] = min(dp[i], cur);
            }
        }
    }
    // if dp[i].second > 0, then the answer is dp[i].first + 1
    cout << dp[(1 << n) - 1][0] + (dp[(1 << n) - 1][1] > 0);
}