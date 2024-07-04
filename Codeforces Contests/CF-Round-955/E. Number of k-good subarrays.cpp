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

map<pair<int, int>, int> m;

int solve(int n, int k) {
	// print(n, k);
	// cout.flush();
	if (k == 0) {
		return 1;
	}

	if (n < ((1ll << (k + 1)) - 1)) {
		n %= MOD;
		return ((n + 2) * (n + 1) / 2) % MOD;
	}

	if (n == 0) {
		return 0;
	}

	if (m.count({n, k})) {
		return m[{n, k}];
	}
	pair<int, int> o = {n, k};

	int i = 63 - __builtin_clzll(n);
	int x = 1ll << i;

	n ^= 1ll << i;
	int res = (solve(x - 1, k) + solve(n, k - 1)) % MOD;
	if (i > k) {
		// print(n ^ (1ll << i), k, res);
		m[o] = res;
		return res;
	}

	x %= MOD;
	res = (res + x * (min(n + 1, ((1ll << k) - 1)) % MOD)) % MOD;
	// print(n ^ (1ll << i), k, res);
	m[o] = res;
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);
		n--;
		
		print(solve(n, k));
	}
}

