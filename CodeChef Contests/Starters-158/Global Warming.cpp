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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = 998244353;

const int N = 1e6;
int fact[N + 1];

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
	return (a * mod_pow(b, MOD - 2)) % MOD;
}

int nCr(int n, int r) {
	if (r < 0 or r > n) {
		return 0;
	}

	return mod_div(fact[n], (fact[r] * fact[n - r]) % MOD);
}

int32_t main() {
	fact[0] = 1;
	range(i, 1, N + 1) {
		fact[i] = (i * fact[i - 1]) % MOD;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		k--;
		int x = n - 2 - k;
		int res = 0;
		range(u, (x + 1) / 2, x + 1) {
			if (2 * u > n - 1) {
				continue;
			}

			int v = x - u;
			int p = u - 1 - v;

			int a = 0;
			if (k >= p) {
				a = (nCr(u - 1, v) * nCr(u + k - p - 1, k - p)) % MOD;
			}

			p++;

			int b = 0;
			if (k >= p) {
				b = (nCr(u, v) * nCr(u + k - p, k - p)) % MOD;
			}

			res = (res + (a + b) * (n - u - 1)) % MOD;
		}
		print(res);
	}
}
