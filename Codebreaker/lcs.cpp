// https://codebreaker.xyz/problem/lcs
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
	string a, b;
	input(a, b);

	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n, vector<int>(m));
	dp[0][0] = a[0] == b[0];
	range(i, 1, n) {
		dp[i][0] = dp[i - 1][0] or a[i] == b[0];
	}
	range(j, 1, m) {
		dp[0][j] = dp[0][j - 1] or a[0] == b[j];
	}
	range(i, 1, n) {
		range(j, 1, m) {
			if (a[i] == b[j]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			dp[i][j] = max({
				dp[i][j],
				dp[i - 1][j],
				dp[i][j - 1]
			});
		}
	}
	
	print(dp[n - 1][m - 1]);
}
