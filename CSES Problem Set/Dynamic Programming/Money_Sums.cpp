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

	int N = 1e5;
	vector<vector<bool>> dp(n, vector<bool>(N + 1, false));
	dp[0][0] = dp[0][a[0]] = true;
	range(i, 1, n) {
		dp[i][0] = true;
		range(j, 1, N + 1) {
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i]) {
				dp[i][j] = dp[i][j] or dp[i - 1][j - a[i]];
			}
		}
	}

	vector<int> res;
	range(j, 1, N + 1) {
		if (dp[n - 1][j]) {
			res.push_back(j);
		}
	}

	print(res.size());
	arrPrint(res);
}
