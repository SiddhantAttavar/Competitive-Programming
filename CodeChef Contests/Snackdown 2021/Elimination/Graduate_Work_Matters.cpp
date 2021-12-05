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
				graph[i][j] = graph[j][i] = c + d * abs(i - j);
			}
		}
		vector<int> dp(n, LONG_LONG_MAX);
		vector<int> p(n);
		dp[0] = 0;
		p[0] = 0;
		range(i, 1, n) {
			dp[i] = dp[i - 1] + graph[i - 1][i] + graph[p[i]][i];
			p[i] = p[i - 1];
			int currSum = graph[i - 1][i];
			for (int j = i - 2; j >= 0; j--) {
				int x = dp[j] + graph[j][i] + currSum + graph[p[j]][j + 1] - graph[p[j]][j];
				if (x < dp[i]) {
					dp[i] = x;
					p[i] = i - 1;
				}
				currSum += graph[j][j + 1];
			}
		}
		print(dp[n - 1]);
	}
}
