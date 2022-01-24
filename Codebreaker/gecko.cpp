// https://codebreaker.xyz/problem/gecko
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	
	int n, m;
	input(n, m);
	vector<vector<int>> a(n, vector<int>(m));
	range(i, 0, n) {
		arrPut(a[i]);
	}

	vector<vector<int>> dp(n, vector<int>(m));
	range(j, 0, m) {
		dp[0][j] = a[0][j];
	}
	range(i, 1, n) {
		dp[i][0] = a[i][0] + max(
			dp[i - 1][0],
			dp[i - 1][1]
		);
		range(j, 1, m - 1) {
			dp[i][j] = a[i][j] + max({
				dp[i - 1][j - 1],
				dp[i - 1][j],
				dp[i - 1][j + 1],
			});
		}
		dp[i][m - 1] = a[i][m - 1] + max(
			dp[i - 1][m - 2],
			dp[i - 1][m - 1]
		);
	}
	
	print(*max_element(dp[n - 1].begin(), dp[n - 1].end()));
}
