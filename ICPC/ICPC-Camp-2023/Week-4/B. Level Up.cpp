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

	const int INF = 1e16;

	int n, s1, s2;
	input(n, s1, s2);

	vector<int> x(n), t(n), y(n), r(n);
	vector<vector<int>> v(n, vector<int>(4));
	range(i, 0, n) {
		input(v[i][0], v[i][1], v[i][2], v[i][3]);
	}
	sort(v.begin(), v.end());
	range(i, 0, n) {
		x[i] = v[i][0];
		t[i] = v[i][1];
		y[i] = v[i][2];
		r[i] = v[i][3];
	}

	vector<vector<int>> dp(s1 + 501, vector<int>(s2 + 1, INF));
	dp[0][0] = 0;
	range(i, 0, n) {
		for (int j = s1 + 500; j >= 0; j--) {
			for (int k = s2; k>= 0; k--) {
				// print(j, k, x[i], y[i]);
				// cout.flush();
				dp[j][k] = min({
					dp[j][k],
					(j >= x[i] and ((j - x[i]) < s1)) ? dp[j - x[i]][k] + t[i] : INF,
					k >= y[i] ? dp[j][k - y[i]] + r[i] : INF
				});
			}
		}
	}

	int res = INF;
	range(i, s1, s1 + 501) {
		range(j, 0,  s2 + 1) {
			if ((i + j) >= (s1 + s2)) {
				res = min(res, dp[i][j]);
			}
		}
	}
	print(res == INF ? -1 : res);
}
