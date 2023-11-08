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

		string s;
		input(s);

		if (n == 1) {
			print("Yes");
			continue;
		}

		vector<vector<bool>> dp(n, vector<bool>(2, false));
		vector<vector<bool>> dp1(n, vector<bool>(2, false));
		dp[0][s[0] - '0'] = true;
		dp1[0][!(s[0] - '0')] = true;
		dp[1][0] = dp[1][1] = s[0] == s[1];
		if (s[0] != s[1]) {
			dp1[1][s[0] - '0'] = true;
		}
		range(i, 2, n) {
			dp[i][s[i] - '0'] = dp[i - 1][s[i] - '0'];
			dp[i][!(s[i] - '0')] = dp1[i - 1][!(s[i] - '0')];
			dp1[i][!(s[i] - '0')] = dp[i - 1][!(s[i] - '0')];
			if (s[i] == s[i - 1]) {
				dp[i][0] = dp[i][0] or dp[i - 2][0];
				dp[i][1] = dp[i][1] or dp[i - 2][1];
				dp1[i][s[i] - '0'] = dp1[i - 2][s[i] - '0'];
			}
		}

		range(i, 0, n) {
			arrPrint(dp[i]);
		}
		print("");
		range(i, 0, n) {
			arrPrint(dp1[i]);
		}

		if (dp[n - 1][0] or dp[n - 1][1]) {
			print("Yes");
		}
		else {
			print("No");
		}
	}
}
