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
const int MOD = 998244353;

int32_t main() {
	setup();
	int n, k;
	input(n, k);

	vector<vector<int>> dp(k, vector<int>(n, 0));
	vector<vector<int>> pref(k, vector<int>(n, 0));
	fill(dp[0].begin(), dp[0].end(), 1);
	range(j, 0, n) {
		pref[0][j] = j + 1;
	}
	range(i, 1, k - 1) {
		pref[i][1] = dp[i][1] = dp[i - 1][0];
		range(j, 2, n - 1) {
			dp[i][j] = (pref[i - 1][j - 1] - dp[i - 1][j - 2] + MOD) % MOD;
			pref[i][j] = (pref[i][j - 1] + dp[i][j]) % MOD;
		}
		if (n >= 3) {
			dp[i][n - 1] = pref[i - 1][n - 2];
		}
	}

	pref[k - 1][1] = dp[k - 1][1] = dp[k - 1 - 1][0];
	range(j, 2, n - 1) {
		dp[k - 1][j] = (pref[k - 2][j - 1] - dp[k - 2][j - 2] + MOD + pref[k - 1][j - 1] - dp[k - 1][j - 2] + MOD) % MOD;
		pref[k - 1][j] = (pref[k - 1][j - 1] + dp[k - 1][j]) % MOD;
	}
	if (n >= 3) {
		dp[k - 1][n - 1] = (pref[k - 2][n - 2] + pref[k - 1][n - 2]) % MOD;
	}

	print(dp[k - 1][n - 1]);
}
