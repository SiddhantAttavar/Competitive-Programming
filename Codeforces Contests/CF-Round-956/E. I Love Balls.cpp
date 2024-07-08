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
	return (a * mod_pow(b, MOD - 2)) % MOD;
}

int32_t main() {
	int N = 4e5;
	vector<int> fact(N + 1, 1), inv_fact(N + 1, 1);
	range(i, 2, N + 1) {
		fact[i] = (fact[i - 1] * i) % MOD;
		inv_fact[i] = mod_div(1, fact[i]);
	}

	vector<int> pref_inv(N + 1, 1);
	range(i, 1, N + 1) {
		pref_inv[i] = (pref_inv[i - 1] + inv_fact[i]) % MOD;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> v(n);
		arrPut(v);

		int a = 0, b = 0;
		range(i, 0, k) {
			a = (a + v[i]) % MOD;
		}

		if (k == n) {
			print(a, 0);
			continue;
		}

		range(i, k, n) {
			b = (b + v[i]) % MOD;
		}
		b = mod_div(b, n - k);

		int l = ((n - k + 1) / 2 * b) % MOD;
		l = (l + mod_div((n - k + 2) / 2, n - k + 1) * a) % MOD;
		print(l, (a + (n - k) * b - l + MOD) % MOD);
	}
}
