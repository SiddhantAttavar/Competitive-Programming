#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, d; input(n, d);
		vector<vector<int>> graph(n, vector<int>(n));
		vector<bool> v(n, false);
		v[0] = true;
		range(i, 0, n) {
			graph[i][i] = -1;
			range(j, i + 1, n) {
				int c; input(c);
				graph[i][j] = graph[j][i] = c;
			}
		}
		vector<vector<int>> dp(n, vector<int>(n, LONG_LONG_MAX));
		vector<int> res(n, LONG_LONG_MAX);
		vector<int> prefSum(n, 0);
		range(i, 1, n) {
			prefSum[i] = prefSum[i - 1] + graph[i - 1][i];
		}
		dp[0][0] = 0;
		res[0] = 0;
		range(i, 1, n) {
			dp[0][i] = graph[0][i] + prefSum[i - 1];
			dp[i - 1][i] = graph[i - 1][i] + min(res[i - 1], dp[i - 1][max(0ll, i - 2)]);
			range(j, 1, i - 1) {
				dp[j][i] = res[j + 1] + graph[j][i] + prefSum[i - 1] - prefSum[j + 1];
			}
			range(j, 0, i) {
				res[i] = min(res[i], dp[j][i]);
			}
		}
		int ans = LONG_LONG_MAX;
		range(i, 0, n - 2) {
			ans = min(ans, dp[i][n - 1] + graph[n - 2][n - 1]);
		}
		print(ans + 2 * (n - 1) * d);
	}
}
