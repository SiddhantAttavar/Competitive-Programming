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
	int M = 1e6, N = 100, K = 100;
	vector<int> f(M + 1, 1);
	rep(i, 2, M + 1) {
		f[i] = i * f[i - 1] % MOD;
	}

	vector<int> g(N + 1);
	rep(i, 1, N + 1) {
		g[i] = mod_pow(2, i * (i - 1) / 2);
	}

	vector<int> c(N + 1, 0);
	rep(i, 1, N + 1) {
		rep(k, 1, i + 1) {
			c[i] = (c[i] + (k * mod_div(f[i], f[k] * f[i - k] % MOD) % MOD) * (c[k] * g[i - k] % MOD)) % MOD;
		}
		c[i] = (g[i] - mod_div(c[i], i) + MOD) % MOD;
	}

	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
	rep(i, 1, N + 1) {
		dp[i][1] = c[i];
		rep(j, 1, min((int) i, K) + 1) {
			rep(s, 1, i + 1) {
				dp[i][j] = (dp[i][j] + mod_div(f[i - 1], f[s - 1] * f[i - s] % MOD) * (c[s] * dp[i - s][j - 1] % MOD)) % MOD;
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		print(dp[n][k]);
	}
}
