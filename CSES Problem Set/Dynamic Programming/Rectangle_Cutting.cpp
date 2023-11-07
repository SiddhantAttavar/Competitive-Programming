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

	int a, b;
	input(a, b);

	vector<vector<int>> dp(a, vector<int>(b, 0));
	range(i, 1, a) {
		dp[i][0] = i;
	}

	range(j, 1, b) {
		dp[0][j] = j;
	}

	range(i, 1, a) {
		range(j, 1, b) {
			if (i == j) {
				continue;
			}

			dp[i][j] = 1e18;
			range(x, 0, i) {
				dp[i][j] = min(dp[i][j], dp[x][j] + dp[i - x - 1][j] + 1);
			}
			range(y, 0, j) {
				dp[i][j] = min(dp[i][j], dp[i][y] + dp[i][j - y - 1] + 1);
			}
		}
	}

	print(dp[a - 1][b - 1]);
}
