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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
	int N = 5e5;
	vector<int> fact(N + 1, 1);
	rep(i, 2, N + 1) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		vector<int> c(26);
		arrput(c);

		int n = accumulate(c.begin(), c.end(), 0ll);

		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (int i : c) {
			if (i == 0) {
				continue;
			}
			for (int j = n; j >= i; j--) {
				dp[j] = (dp[j] + dp[j - i]) % MOD;
			}
		}

		int res = fact[n / 2] * fact[(n + 1) / 2] % MOD;
		for (int i : c) {
			res = mod_div(res, fact[i]);
		}
		print((res * dp[n / 2]) % MOD);
	}
}
