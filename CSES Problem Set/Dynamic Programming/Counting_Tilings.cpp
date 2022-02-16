#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	
	const int MOD = 1e9 + 7;
	int n, m;
	input(n, m);

	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(1 << (n + 1))));
	dp[n][0][0] = 1;
	range(i, 1, m + 1) {
		range(j, 0, 1 << n) {
			dp[0][i][j << 1] = dp[n][i - 1][j];
		}

		range(j, 1, n + 1) {
			int x = 1 << (j - 1);
			int y = 1 << j;

			range(k, 0, 1 << (n + 1)) {
				dp[j - 1][i][k] %= MOD;

				if ((k & x) and (k & y)) {
					continue;
				}

				if (k & x) {
					dp[j][i][k ^ x] += dp[j - 1][i][k];
				}
				else if (k & y) {
					dp[j][i][k ^ y] += dp[j - 1][i][k];
				}
				else {
					dp[j][i][k ^ x] += dp[j - 1][i][k];
                    dp[j][i][k ^ y] += dp[j - 1][i][k];
				}
			}
		}
	}
	
	print(dp[n][m][0] % MOD);
}
