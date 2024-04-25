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

int N = 3e5;
vector<int> fact(N + 1, 1);

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

int mod_ncr(int n, int r) {
	return mod_div(fact[n], (fact[r] * fact[n - r]) % MOD);
}

int32_t main() {
	range(i, 2, N + 1) {
		fact[i] = (i * fact[i - 1]) % MOD;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		range(i, 0, k) {
			int x, y;
			input(x, y);

			n -= 1 + (x != y);
		}

		int res = 0;
		range(i, 0, n / 2 + 1) {
			res = (res + mod_ncr(n, i) * mod_div(fact[n - i], fact[n - 2 * i])) % MOD;
		}
		print(res);
	}
}
