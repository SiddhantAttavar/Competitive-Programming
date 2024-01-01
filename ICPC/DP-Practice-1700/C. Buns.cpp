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

	int n, m, c0, d0;
	input(n, m, c0, d0);

	vector<int> a(m), b(m), c(m), d(m);
	range(i, 0, m) {
		input(a[i], b[i], c[i], d[i]);
	}

	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m, vector<int>(101, 0)));
	range(j, 0, m) {
		range(i, 0, n + 1) {
			range(k, 0, 101) {
				if (j == 0) {
					dp[i][j][k] = (i / c0) * d0;
				}
				else {
					dp[i][j][k] = dp[i][j - 1][a[j - 1]];
				}

				if (i >= c[j] and k >= b[j]) {
					dp[i][j][k] = max(dp[i][j][k], dp[i - c[j]][j][k - b[j]] + d[j]);
				}
			}
		}
	}

	print(dp[n][m - 1][a[m - 1]]);
}
