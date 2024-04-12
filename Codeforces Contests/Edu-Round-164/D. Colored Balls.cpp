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

int mod_pow(int a, int b) {
	int res = 1;
	while (b > 0) {
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
	setup();
	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);
	sort(a.begin(), a.end());

	int N = 1e4 + 1;
	vector<int> dp(N + 1, 0);
	dp[0] = 1;

	int res = 0;
	for (int x : a) {
		for (int i = N; i >= x; i--) {
			if (i <= 2 * x - 1) {
				res = (res + x * dp[i - x]) % MOD;
				res = (res - ((i + 1) / 2) * dp[i - x] + MOD) % MOD;
			}
			dp[i] = (dp[i] + dp[i - x]) % MOD;
		}
		// print(res);
	}

	int x = 0;
	for (int i : a) {
		x = (x + i) % MOD;
	}
	x = (x * mod_pow(2, n - 1)) % MOD;

	bool flag = false;
	for (int i : a) {
		if (i % 2) {
			flag = true;
			break;
		}
	}

	int y = mod_div(x, 2);
	if (flag) {
		y = (y + mod_div(mod_pow(2, n - 1), 2)) % MOD;
	}

	print((res + y) % MOD);
}
