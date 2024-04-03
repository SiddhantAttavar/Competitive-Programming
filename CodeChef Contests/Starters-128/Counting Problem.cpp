#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}

		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int mod_div(int a, int b) {
	return (a * mod_pow(b, MOD - 2));
}

int32_t main() {
	int N = 2e5;
	vector<int> fact(N + 1, 1), inv_fact(N + 1, 1);
	range(i, 2, N + 1) {
		fact[i] = (i * fact[i - 1]) % MOD;
		inv_fact[i] = mod_div(1, fact[i]);
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		if (k == 1) {
			int res = 0;
			range(r, 0, min(k, n)) {
				res = (res + ((mod_pow(m - 1, r) * mod_pow(m, n - r - 1)) % MOD)) % MOD;
			}
			print(res);
			continue;
		}

		if (k == m) {
			int res = 0;
			range(r, 0, n) {
				res = (res + ((mod_pow(m - 1, r) * mod_pow(m, n - r - 1)) % MOD)) % MOD;
			}
			print(res);
			continue;
		}

		int res = 0, p = 1;
		int o = mod_pow(m, n - 1);
		int b = mod_div(k - 1, m);
		int c = 1;
		range(r, 0, min(k, n)) {
			int a = (fact[n] * ((inv_fact[r + 1] * inv_fact[n - r - 1]) % MOD)) % MOD;
			res = (res + ((
				((o * c) % MOD) * ((a * b) % MOD)
			) % MOD)) % MOD;
			print(r, res);
			b = (b * mod_div(k - 1, m)) % MOD;
			c = (c * mod_div(m - k, k - 1)) % MOD;
		}

		print(res);
	}
}
