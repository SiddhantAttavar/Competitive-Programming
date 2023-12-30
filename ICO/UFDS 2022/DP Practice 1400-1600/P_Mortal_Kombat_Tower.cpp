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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		if (n == 1) {
			print(a[0]);
			continue;
		}

		vector<int> dp(n + 1, 1e9);
		dp[0] = 0;
		dp[1] = a[0];
		range(i, 1, n) {
			dp[i + 1] = dp[i - 1] + a[i - 1];
			if (i >= 2) {
				dp[i + 1] = min(dp[i + 1], dp[i - 2] + a[i - 2]);
			}
			if (i >= 3) {
				dp[i + 1] = min(dp[i + 1], dp[i - 3] + a[i - 3] + a[i - 2]);
			}
		}

		int res = min(dp[n], dp[n - 1] + a[n - 1]);
		if (n > 2) {
			res = min(res, dp[n - 2] + a[n - 2] + a[n - 1]);
		}
		// arrPrint(dp);

		print(res);
	}
}
