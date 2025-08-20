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
	return a * mod_pow(b, MOD - 2) % MOD;
}

int get(int n, int k, vector<int> &fact) {
	if (n == 0 or k == 0 or n < k) {
		return 0;
	}
	return mod_div(
		fact[n] * fact[n - 1] % MOD,
		fact[n - k] * fact[k - 1] % MOD
	);
	// return mod_div(fact[n + k - 1], fact[k - 1]) % MOD;
	// int res = 0;
	// rep(j, 1, k + 1) {
	// 	// int c = mod_div(fact[k], fact[j] * fact[k - j] % MOD) * mod_div(fact[n - 1], fact[j - 1] * fact[n - j] % MOD) % MOD;
	// 	int c = mod_div(fact[k], fact[j] * fact[k - j] % MOD) * mod_pow(j, n) % MOD;
	// 	if (k % 2 == j % 2) {
	// 		res = (res + c) % MOD;
	// 	}
	// 	else {
	// 		res = (res - c + MOD) % MOD;
	// 	}
	// }
	// return res * fact[n] % MOD;
}

int solve(int x, int y, int z, vector<int> &fact) {
	int res = 0;
	rep(i, 0, x + 1) {
		int c = get(y, i, fact) * get(z, x - i, fact) % MOD;
		res = (res + c * mod_div(fact[x], fact[i] * fact[x - i] % MOD)) % MOD;
	}
	return res;
}

int32_t main() {
	int N = 1e6;
	vector<int> fact(N + 1, 1);
	rep(i, 2, N + 1) {
		fact[i] = fact[i - 1] * i % MOD;
	}

	// print(get(2, 2, fact));
	// print(get(3, 1, fact));
	// print(solve(2, 4, 3, fact));

	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		int y = n / 3 + (n % 3 >= 1), z = n / 3 + (n % 3 == 2), x = n / 3;
		print((
			solve(x - 1, y, z, fact) +
			solve(x, y, z, fact) +
			solve(x, y, z, fact) +
			solve(x + 1, y, z, fact)
	  	) * fact[x] % MOD);
	}
}
