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

	vector<string> a(n);
	arrPut(a);

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	dp[0][1] = 1;
	range(i, 1, n + 1) {
		range(j, 1, n + 1) {
			dp[i][j] = (a[i - 1][j - 1] == '.') *  (dp[i - 1][j] + dp[i][j - 1]) % ((int) 1e9 + 7);
		}
	}

	print(dp[n][n]);
}
