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

int modDiv(int a, int b, int m) {
	int x = 1, z = b;
	int y = m - 2;
	while (y) {
		if (y & 1) {
			x = (x * z) % m;
		}

		z = (z * z) % m;
		y >>= 1;
	}
	return (a * x) % m;
}

int32_t main() {
	setup();

	int n;
	input(n);

	int MOD = (int) 1e9 + 7;
	int N = n * (n + 1) / 2;

	if (N % 2 != 0) {
		print(0);
		return 0;
	}

	N /= 2;

	vector<vector<int>> dp(n, vector<int>(N + 1, false));
	dp[0][0] = dp[0][1] = 1;
	range(i, 1, n) {
		dp[i][0] = 1;
		range(j, 1, N + 1) {
			dp[i][j] = dp[i - 1][j];
			if (j > i) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - i - 1]) % MOD;
			}
		}
	}

	print(modDiv(dp[n - 1][N], 2, MOD));
}
