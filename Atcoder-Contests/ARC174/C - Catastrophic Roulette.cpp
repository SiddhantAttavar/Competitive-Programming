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
const int MOD = 998244353;

int mod_div(int a, int b) {
	int x = MOD - 2, res = a % MOD;
	b %= MOD;
	while (x) {
		if (x & 1) {
			res = (res * b) % MOD;
		}

		b = (b * b) % MOD;
		x >>= 1;
	}
	return res;
}

int32_t main() {
	setup();

	int n;
	input(n);

	// print(mod_div(1, 3));
	vector<int> f(n + 1);
	f[0] = 0;
	f[1] = mod_div((n * (n - 1)) % MOD, 2 * n - 1);
	range(i, 2, n + 1) {
		f[i] = mod_div(
			(
				((n * (n - i)) % MOD) +
				((((i * (2 * n - 2 * i + 1)) % MOD) * f[i - 1]) % MOD) +
				((((i * (i - 1)) % MOD) * f[i - 2]) % MOD)
			) % MOD,
			(i * (2 * n - i)) % MOD
		);
	}
	// arrPrint(f);

	print(f[n], f[n - 1]);
}
