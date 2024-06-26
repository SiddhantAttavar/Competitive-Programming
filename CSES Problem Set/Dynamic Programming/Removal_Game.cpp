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

	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	vector<int> pref(n + 1, 0);
	range(i, 0, n) {
		pref[i + 1] = pref[i] + a[i];
	}

	vector<vector<int>> dp(n, vector<int>(n));
	range(i, 0, n) {
		dp[i][i] = a[i];
	}

	range(i, 0, n - 1) {
		dp[i][i + 1] = max(a[i], a[i + 1]);
	}

	range(l, 3, n + 1) {
		range(i, 0, n - l + 1) {
			int j = i + l - 1;
			dp[i][j] = max(a[i] + pref[j + 1] - pref[i + 1] - dp[i + 1][j], a[j] + pref[j] - pref[i] - dp[i][j - 1]);
		}
	}

	// range(i, 0, n) {
	// 	arrPrint(dp[i]);
	// }
	// print("");

	print(dp[0][n - 1]);
}
