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
const int MOD = (int) 1e9 + 7; //998244353;

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}

		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int mod_div(int a, int b) {
	return a * mod_pow(b, MOD - 2) % MOD;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, l, k;
		input(n, l, k);

		vector<vector<vector<int>>> dp(n * l + 1, vector<vector<int>>(min(n, l) + 1, vector<int>(min(n, l) + 1, 0)));
		vector<int> res(n, 0);
		dp[0][0][0] = 1;
		rep(i, 1ll, n * l + 1) {
			if (i <= l) {
				dp[i][0][i] = dp[i - 1][0][i - 1] * mod_div(l - i, l - i + 1) % MOD;
			}
			rep(x, 1, min(i, l) + 1) {
				rep(y, 1, min(i, l) - x + 1) {
					dp[i][x][y] = dp[i][x][y - 1] * mod_div(l - x - y, l - x - y + 1) % MOD;
				}
				rep(y, 0, min(i, l) - x + 1) {
					print("debug", x, y, l, i);
					cout.flush();
					dp[i][x][0] = (dp[i][x][0] + dp[i - 1][x - 1][y] * mod_div(1, l - x - y + 1)) % MOD;
					print("debug2");
					cout.flush();
				}
				res[(i - 1) % n] = (res[(i - 1) % n] + dp[i][x][0]) % MOD;
			}
		}

		arrprint(res);
	}
}
