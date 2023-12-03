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

	int n, s, m, l;
	input(n, s, m, l);

	vector<int> dp(n + 24, 1e18);
	dp[0] = 0;
	range(i, 6, n + 24) {
		dp[i] = dp[i - 6] + s;
		if (i >= 8) {
			dp[i] = min(dp[i], dp[i - 8] + m);
		}
		if (i >= 12) {
			dp[i] = min(dp[i], dp[i - 12] + l);
		}
	}
	// arrPrint(dp);

	print(*min_element(dp.begin() + n, dp.end()));
}
