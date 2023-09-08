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
		int x, y;
		input(x, y);

		vector<int> a(x), b(y);
		arrPut(a);
		arrPut(b);

		vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
		range(i, 0, x) {
			range(j, 0, y) {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);

				if (a[i] == b[j]) {
					dp[i + 1][j + 1] = max(dp[i + 1][j + 1], 1 + dp[i][j]);
				}
			}
		}

		print(dp[x][y]);
	}
}
