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

void solve(string &s, vector<vector<int>> &dp, int k, string &res, int z) {
	if (res.size() == s.size()) {
		return;
	}

	int i = res.size();
	if (s[i] != '?') {
		res += s[i];
		solve(s, dp, k, res, 9);
		return;
	}

	for (int j = z; j > 0; j--) {
		if (dp[i][j] >= k) {
			res += j + '0';
			solve(s, dp, k, res, j == 2 ? 6 : 9);
			return;
		}
		k -= dp[i][j];
	}
	res += '0';
	solve(s, dp, k, res, 9);
}

int32_t main() {
	int INF = 1e16;
	setup(); int tc; input(tc); range(t, 1, tc + 1) {
		string s;
		input(s);

		int k;
		input(k);

		int n = s.size();
		vector<vector<int>> dp(n + 1, vector<int>(10, 0));
		vector<int> f(n + 1, 0);
		f[n] = 1;
		f[n - 1] = s[n - 1] != '0';
		dp[n][0] = 1;
		range(j, 1, 10) {
			dp[n - 1][j] = (s[n - 1] == '?' or s[n - 1] - '0' == j);
		}

		for (int i = n - 2; i >= 0; i--) {
			bool flag = s[i] == '?';
			range(j, 1, 10) {
				if (s[i] - '0' != j and !flag) {
					continue;
				}

				s[i] = '0' + j;

				int c = f[i + 1];
				if (j <= 2 and (s[i + 1] == '?' or j == 1 or (j == 2 and s[i + 1] <= '6'))) {
					c = (f[i + 1] + f[i + 2]) % MOD;
				}

				if (c == f[i + 1] and c != f[i]) {
					if (f[i] == (f[i + 1] + f[i + 2]) % MOD) {
						continue;
					}
					f[i] = c;
				}

				if (c == (f[i + 1] + f[i + 2]) % MOD and c != f[i]) {
					dp[i] = vector<int>(10, 0);
					f[i] = c;
				}

				int p = min(INF, accumulate(dp[i + 1].begin(), dp[i + 1].end(), 0ll));
				if (c == f[i + 1]) {
					dp[i][j] = p;
					continue;
				}

				if (s[i + 1] != '?') {
					dp[i][j] = min(INF, dp[i][j] + p);
					continue;
				}

				if (j == 1) {
					dp[i][j] = min(INF, dp[i][j] + p);
				}
				else if (j == 2) {
					dp[i][j] = min(INF, dp[i][j] + accumulate(dp[i + 1].begin(), dp[i + 1].begin() + 7, 0ll));
				}
			}
			if (flag) {
				s[i] = '?';
			}
		}
		// range(i, 0, n + 1) {
		// 	arrPrint(dp[i]);
		// }

		string res;
		solve(s, dp, k, res, 9);
		cout << "Case #" << t << ": " << res << ' ' << f[0] << endl;
	}
}
