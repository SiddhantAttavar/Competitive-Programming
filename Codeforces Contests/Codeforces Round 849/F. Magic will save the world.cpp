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
		int w, f;
		input(w, f);

		int n;
		input(n);

		vector<int> s(n);
		arrPut(s);

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

		range(i, 1, n + 1) {
			int x = dp[i - 1][0] - w * (i - 1);
			int y = s[i - 1] - x;
			dp[i][0] = dp[i - 1][0] + y / w;
		}

		range(j, 1, n + 1) {
			int x = dp[0][j - 1] - f * (j - 1);
			int y = s[j - 1] - x;
			dp[0][j] = dp[0][j - 1] + y / w;
		}

		range(i, 1, n + 1) {
			range(j, 1, n + 1) {
				if (i + j > n) {
					break;
				}

				int x = dp[i - 1][j] - w * (i - 1);
				int y = s[i + j - 1] - x;
				dp[i][j] = dp[i - 1][j] + y / w;

				x = dp[i][j - 1] - f * (j - 1);
				y = s[i + j - 1] - x;
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + y / w);
			}
		}

		range(i, 0, n + 1) {
			arrPrint(dp[i]);
		}

		int res = 1e9;
		range(i, 0, n + 1) {
			res = min(res, dp[i][n - i]);
		}
		print(res);
		cout << endl;
	}
}
