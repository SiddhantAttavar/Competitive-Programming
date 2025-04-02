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
		if (b) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrput(a);

		vector<int> dp(k + 1, 0);
		dp[0] = 1;
		rep(i, 0, n) {
			vector<int> pref(k + 1, 0);
			pref[0] = dp[0];
			rep(j, 0, k) {
				pref[j + 1] = (pref[j] + dp[j + 1]) % MOD;
			}
			if (a[i] != -1) {
				dp[a[i]] = (dp[a[i]] + pref[a[i] - 1]) % MOD;
				continue;
			}

			dp[0] = dp[0] * k % MOD;
			rep(j, 1, k + 1) {
				dp[j] = (dp[j] * k + pref[j - 1]) % MOD;
			}
			// arrprint(dp);
		}
		print(accumulate(dp.begin() + 1, dp.end(), 0ll) % MOD);
	}
}
