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

const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<int> a(n);
	arrPut(a);

	vector<vector<int>> dp(n, vector<int>(m + 2, 0));
	if (a[0] == 0) {
		fill(dp[0].begin() + 1, dp[0].begin() + m + 1, 1);
	}
	else {
		dp[0][a[0]] = 1;
	}

	range(i, 1, n) {
		if (a[i] == 0) {
			range(j, 1, m + 1) {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
			}
		}
		else {
			dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) % MOD;
		}
	}

	int res = 0;
	for (int i : dp[n - 1]) {
		res = (res + i) % MOD;
	}

	print(res);
}
