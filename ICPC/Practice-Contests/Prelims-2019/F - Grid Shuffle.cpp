#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
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
	return a % MOD * mod_pow(b % MOD, MOD - 2) % MOD;
}

int get(int n, int k) {
	int N = 2 * n * n % MOD;
	int d = 1, a = 0, c = 0;
	rep(i, 0, k) {
		int nd = (
			mod_div(2 * d, N) + 
			mod_div(2 * a, N) + 
			mod_div((2 * n - 2) * d, 2 * n)
		) % MOD;
		int na = (
			mod_div((n - 1) * d, N) + 
			mod_div(n * a, N) + 
			mod_div(c, N) +
			mod_div((2 * n - 2) * a, 2 * n)
		) % MOD;
		int nc = (1 - nd - 2 * na + 3 * MOD) % MOD;
		d = nd, a = na, c = nc;
	}
	return d;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k, x, y;
		input(n, k, x, y);

		int N = 2 * n * n % MOD;
		int d = 1, a = 0, c = 0;
		rep(i, 0, k) {
			int nd = (
				mod_div(2 * a, N) + 
				mod_div(((2 * n - 2) * n + 2) * d, N)
			) % MOD;
			int na = (
				mod_div((n - 1) * d, N) + 
				mod_div(c, N) +
				mod_div((2 * n - 1) * n * a, N)
			) % MOD;
			int nc = (
				mod_div(2 * (n - 1) * a, N) +
				mod_div((2 * n - 2) * (n + 1) * c, N)
			) % MOD;
			// int na = mod_div(1 - nd - nc + 2 * MOD, 2);
			d = nd, a = na, c = nc;
			assert((d + 2 * a + c) % MOD == 1);
		}
		print(d);
	}
}
