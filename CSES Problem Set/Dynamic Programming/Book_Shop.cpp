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
// #define int long long

int32_t main() {
	setup();

	int n, x;
	input(n, x);

	vector<int> h(n), s(n);
	arrPut(h);
	arrPut(s);

	vector<vector<int>> dp(n, vector<int>(x + 1, 0));
	dp[0][0] = 0;
	range(j, h[0], x + 1) {
		dp[0][j] = s[0];
	}

	range(i, 1, n) {
		dp[i][0] = 0;
		range(j, 1, x + 1) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			if (j >= h[i]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + s[i]);
			}
		}
	}

	print(dp[n - 1][x]);
}
