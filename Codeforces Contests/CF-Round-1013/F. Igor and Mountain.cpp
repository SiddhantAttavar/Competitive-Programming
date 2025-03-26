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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, d;
		input(n, m, d);

		vector<vector<bool>> a(n, vector<bool>(m));
		rep(i, 0, n) {
			string s;
			input(s);
			rep(j, 0, m) {
				a[i][j] = s[j] == 'X';
			}
		}

		int k = 0;
		while (k * k + 1 <= d * d) {
			k++;
		}
		k--;

		vector<int> dp(m, 0), dp2(m, 0), pdp(m + 1, 0);
		dp[0] = a[n - 1][0];
		rep(j, 1, m) {
			dp[j] = a[n - 1][j];
		}
		rep(j, 0, m) {
			pdp[j + 1] = (pdp[j] + dp[j]) % MOD;
		}
		rep(j, 0, m) {
			if (a[n - 1][j]) {
				int l = max(0ll, j - d), r = min(m - 1, j + d);
				dp2[j] = (pdp[r + 1] - pdp[l] - dp[j] + 2 * MOD) % MOD;
			}
		}
		// arrprint(dp);
		// arrprint(dp2);

		for (int i = n - 2; i >= 0; i--) {
			vector<int> pref(m + 1, 0);
			rep(j, 0, m) {
				pref[j + 1] = (pref[j] + dp[j] + dp2[j]) % MOD;
			}
			vector<int> ndp(m, 0), ndp2(m, 0), npdp(m + 1, 0);
			rep(j, 0, m) {
				if (a[i][j]) {
					int l = max(0ll, j - k), r = min(m - 1, j + k);
					// print(j, l, r);
					ndp[j] = (pref[r + 1] - pref[l] + MOD) % MOD;
				}
			}
			rep(j, 0, m) {
				npdp[j + 1] = (npdp[j] + ndp[j]) % MOD;
			}
			rep(j, 0, m) {
				if (a[i][j]) {
					int l = max(0ll, j - d), r = min(m - 1, j + d);
					ndp2[j] = (npdp[r + 1] - npdp[l] - ndp[j] + 2 * MOD) % MOD;
				}
			}
			// print("");
			// arrprint(ndp);
			// arrprint(ndp2);
			dp = ndp;
			dp2 = ndp2;
		}

		int res = 0;
		rep(i, 0, m) {
			res = (res + dp[i] + dp2[i]) % MOD;
		}
		print(res);
	}
}
