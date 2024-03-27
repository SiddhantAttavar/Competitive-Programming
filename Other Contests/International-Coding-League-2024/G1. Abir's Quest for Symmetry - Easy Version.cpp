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
	int N = 1e3;
	vector<int> fact(N + 1, 1);
	range(i, 2, N + 1) {
		fact[i] = (i * fact[i - 1]) % MOD;
	}

	vector<int> dp(N + 1, 0);
	dp[1] = 1;
	range(i, 2, N + 1) {
		dp[i] = mod_pow(2, i * (i - 1) / 2);
		range(k, 1, i) {
			dp[i] = (dp[i] + MOD - mod_div((
				((k * mod_div(fact[i], (fact[k] * fact[i - k]) % MOD)) % MOD) *
				((mod_pow(2, (i - k) * (i - k - 1) / 2) * dp[k]) % MOD)
			) % MOD, i)) % MOD;
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		print((dp[n] + 1) % MOD);
	}
}
