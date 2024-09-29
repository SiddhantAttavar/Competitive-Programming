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
const int MOD = (int) 1e9 + 7; //998244353

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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n), p(n);
		arrPut(a);
		arrPut(p);

		range(i, 0, n) {
			p[i] = mod_div(p[i], 10000);
		}

		vector<int> dp(1024, 0);
		dp[0] = 1;
		range(i, 0, n) {
			vector<int> ndp(1024);
			range(j, 0, 1024) {
				ndp[j] = dp[j] * (1 - p[i]) + dp[j ^ a[i]] * p[i];
				ndp[j] = (ndp[j] % MOD + MOD) % MOD;
			}
			dp = ndp;
		}

		int res = 0;
		range(i, 0, 1024) {
			res = (res + dp[i] * i * i) % MOD;
		}
		print(res);
	}
}
