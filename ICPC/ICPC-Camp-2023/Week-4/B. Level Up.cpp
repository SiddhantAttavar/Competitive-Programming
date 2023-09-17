#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();

	const int INF = 1e18;

	int n, s1, s2;
	input(n, s1, s2);

	vector<int> x(n), t(n), y(n), r(n);
	range(i, 0, n) {
		input(x[i], t[i], y[i], r[i]);
	}

	vector<vector<int>> dp(1001, vector<int>(1001, INF)), ndp(1001, vector<int>(1001, INF));
	dp[0][0] = 0;
	range(i, 0, n) {
		range(j, 0, s1 + x[i] + 1) {
			range(k, 0, s2 + y[i] + 1) {
				ndp[j][k] = min({
					dp[j][k],
					j >= x[i] ? dp[j - x[i]][k] + t[i] : INF,
					k >= y[i] ? dp[j][k - y[i]] + r[i] : INF
				});
			}
		}
		dp = ndp;
	}

	if (dp[s1][s2] == INF) {
		print(-1);
	}
	else {
		int res = 1e18;
		range(i, s1, s1 + s2 + 1) {
			range(j, s1 + s2 - i, 1001) {
				res = min(res, dp[i][j]);
			}
		}
		print(res);
	}
}
