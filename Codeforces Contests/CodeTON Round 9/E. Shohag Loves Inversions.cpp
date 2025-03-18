#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = 998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		if (n == 2) {
			print(1);
			continue;
		}

		vector<vector<int>> dp(n + 2, vector<int>(n * n + 1));
		int p = n * (n - 1) / 2 - 3;
		if (n == 2) {
			p = 0;
		}
		else if (n == 3) {
			p = 1;
		}
		rep(i, 1, p + 1) {
			dp[n][i] = 1;
		}
		for (int l = n - 1; l > 0; l--) {
			rep(x, 1, n * n + 1) {
				rep(j, 0, l) {
					if (x + j <= n * n) {
						dp[l][x] += dp[l + 1][x + j];
					}
				}
				dp[l][x] %= MOD;
			}
		}
		rep(i, 1, n + 1) {
			arrprint(dp[i]);
		}

		int res = 1;
		rep(x, 2, n + 1) {
			rep(y, 2, n - x + 1) {
				rep(z, 0, n - (x + y) + 1) {
					res += dp[x + y + z][y];
				}
			}
		}
		rep(x, 1, n + 1) {
			rep(y, 2, n - x + 1) {
				rep(z, 0, n - (x + y) + 1) {
					res += dp[x + y + z][y];
				}
			}
		}
		res %= MOD;
		print(res);
	}
}
