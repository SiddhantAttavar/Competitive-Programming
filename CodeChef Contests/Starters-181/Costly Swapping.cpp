#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
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
	const int N = 1e6;
	vector<int> fact(N + 1, 1);
	rep(i, 2, N + 1) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n, a, b, c, d;
		input(n, a, b, c, d);

		a = min(a, d);
		b = min(b, c);
		if (a > b) {
			swap(a, b);
		}

		int res = 0;
		rep(k, 0, n / 2 + 1) {
			vector<int> dp(k + 1), c(k + 1);
			c[0] = 1;
			rep(i, 1, k + 1) {
				for (int j = i - 1; j >= 0; j--) {
					dp[i] = (dp[i] + dp[j] + c[j] * a % MOD * (i - j)) % MOD;
					c[i] = (c[i] + c[j]) % MOD;
				}
				for (int j = i - 1; j >= 0; j--) {
					dp[i] = (dp[i] + dp[j] * c[i - j - 1] % MOD + dp[i - j - 1] * c[j] % MOD + c[j] * c[i - j - 1] % MOD * b) % MOD;
					debug(i, j, dp[i]);
					c[i] = (c[i] + c[j] * c[i - j - 1]) % MOD;
				}
			}
			res = (res + dp[k] * mod_div(fact[n], fact[2 * k] * fact[n - 2 * k] % MOD) % MOD * mod_pow(2, n - 2 * k)) % MOD;
			debug(k, res, dp[k]);
		}
		print(res);
	}
}
