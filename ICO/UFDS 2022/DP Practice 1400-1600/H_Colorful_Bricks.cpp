#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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

	int n, m, k;
	input(n, m, k);

	vector<vector<int>> dp(n, vector<int>(k + 1, 0));
	dp[0][0] = m;
	range(i, 1, n) {
		dp[i][0] = dp[i - 1][0];
		range(j, 1, k + 1) {
			dp[i][j] = (dp[i - 1][j - 1] * (m - 1) + dp[i - 1][j]) % 998244353;
		}
	}

	for (vector<int> i : dp) {
		// arrPrint(i);
	}

	print(dp[n - 1][k]);
}
