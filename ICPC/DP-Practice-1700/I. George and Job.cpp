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

	int n, m, k;
	input(n, m, k);

	vector<int> a(n);
	arrPut(a);
	
	vector<int> pref(n + 1, 0);
	range(i, 0, n) {
		pref[i + 1] = pref[i] + a[i];
	}

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	range(i, 1, n + 1) {
		range(j, 1, k + 1) {
			dp[i][j] = dp[i - 1][j];
			if (i >= m) {
				dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + pref[i] - pref[i - m]);
			}
		}
	}

	print(dp[n][k]);
}
