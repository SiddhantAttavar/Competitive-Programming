// https://codebreaker.xyz/problem/4russians
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	
	int n, k;
	input(n, k);
	vector<int> c(n), s(n);
	arrPut(c);
	arrPut(s);
	c.push_back(0);

	if (n == 1) {
		print(s[0]);
		return 0;
	}

	vector<vector<int>> dp(n, vector<int>(k, LLONG_MIN));
	vector<vector<int>> dp2(n, vector<int>(k, LLONG_MIN));
	dp[0][0] = s[0] - c[0] * c[1];
	dp2[0][0] = dp[0][0];
	range(i, 1, n) {
		dp[i][0] = s[i] - c[i - 1] * c[i] - c[i] * c[i + 1];
		dp2[i][0] = max(dp[i][0], dp2[i - 1][0]);
		range(j, 1, min(i + 1, k)) { 
			if (dp2[i - 1][j - 1] != LLONG_MIN) {
				dp[i][j] = dp2[i - 1][j - 1] + s[i] - c[i - 1] * c[i] - c[i] * c[i + 1];
			}
			if (dp[i - 1][j - 1] != LLONG_MIN) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + s[i] + c[i - 1] * c[i] - c[i] * c[i + 1]);
			}

			dp2[i][j] = dp[i][j];
			if (dp2[i - 1][j] != LLONG_MIN) {
				dp2[i][j] = max(dp2[i][j], dp2[i - 1][j]);
			}
		}
	}
	
	// range(j, 0, k) {
	// 	range(i, 0, n) {
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// 	range(i, 0, n) {
	// 		cout << dp2[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	
	int res = 0;
	range(j, 0, k) {
		res = max(res, dp2[n - 1][j]);
	}
	print(res);
}
