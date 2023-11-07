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

	string a, b;
	input(a, b);

	int n = a.size(), m = b.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	dp[0][0] = 0;
	range(i, 0, n) {
		dp[i + 1][0] = dp[i][0] + 1;
	}
	range(j, 0, m) {
		dp[0][j + 1] = dp[0][j] + 1;
	}
	range(i, 0, n) {
		range(j, 0, m) {
			dp[i + 1][j + 1] = min({
				dp[i][j + 1] + 1,
				dp[i + 1][j] + 1,
				dp[i][j] + (a[i] != b[j])
			});
		}
	}

	print(dp[n][m]);
}
