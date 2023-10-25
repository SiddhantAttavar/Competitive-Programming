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

void dfs1(int u, int p, int i, vector<vector<pair<int, char>>> &graph, vector<vector<int>> &dp, string &s) {
	dp[u][i + 1] = dp[u][i];
	for (pair<int, char> x : graph[u]) {
		int v; char c;
		tie(v, c) = x;
		if (v == p) {
			continue;
		}

		dfs1(v, u, i, graph, dp, s);
		dp[u][i + 1] = max({dp[u][i + 1], dp[v][i + 1], dp[v][i] + (c == s[i])});
	}
}

void dfs2(int u, int p, int i, vector<vector<pair<int, char>>> &graph, vector<vector<int>> &dp, string &s) {
	dp[u][i + 1] = dp[u][i + 2];
	for (pair<int, char> x : graph[u]) {
		int v; char c;
		tie(v, c) = x;
		if (v == p) {
			continue;
		}

		dfs1(v, u, i, graph, dp, s);
		dp[u][i + 1] = max({dp[u][i + 1], dp[v][i + 1], dp[v][i + 2] + (c == s[i])});
	}
}

int dfs3(int u, int p, int i, vector<vector<pair<int, char>>> &graph, vector<vector<int>> &dp1, vector<vector<int>> &dp2, string s) {
	int n = graph.size();
	int res = 0;
	if (i >= 0 and i < n) {
		// print(dp1[u][i], dp2[u][i]);
		res = max(dp1[u][i], dp2[u][i]);
	}
	for (pair<int, char> x : graph[u]) {
		int v; char c;
		tie(v, c) = x;

		if (v == p) {
			continue;
		}

		res = max(res, dfs3(v, u, i, graph, dp1, dp2, s));
	}

	range(j, 0, (int) graph[u].size()) {
		int v1; char c1;
		tie(v1, c1) = graph[u][j];
		range(k, j + 1, (int) graph[u].size()) {
			int v2; char c2;
			tie(v2, c2) = graph[u][k];

			if (i + 2 <= n + 1) {
				res = max({res, dp1[v1][i + 1] + dp2[v2][i + 2], dp1[v2][i + 1] + dp2[v1][i + 2]});
			}

			if (i + 3 <= n + 1 and (c1 == s[i + 1] or c2 == s[i + 1])) {
				res = max({res, dp1[v1][i + 1] + dp2[v2][i + 3] + 1, dp1[v2][i + 1] + dp2[v1][i + 3] + 1});
			}

			if (i + 4 <= n + 1 and (c1 == s[i + 2] or c2 == s[i + 2])) {
				res = max({res, dp1[v1][i + 1] + dp2[v2][i + 4] + 1, dp1[v2][i + 1] + dp2[v1][i + 4] + 1});
			}

			if (i + 4 <= n + 1 and ((c1 == s[i + 1] and c2 == s[i + 2]) or (c1 == s[i + 2] and c2 == s[i + 1]))) {
				res = max({res, dp1[v1][i + 1] + dp2[v2][i + 4] + 2, dp1[v2][i + 1] + dp2[v1][i + 4] + 2});
			}
		}
	}

	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		// print("debug");
		// cout.flush();
		int n;
		input(n);

		vector<vector<pair<int, char>>> graph(n);
		range(i, 0, n - 1) {
			int u, v;
			input(u, v);

			char c;
			input(c);

			graph[u - 1].push_back({v - 1, c});
			graph[v - 1].push_back({u - 1, c});
		}

		string s;
		input(s);

		vector<vector<int>> dp1(n, vector<int>(n + 1, 0));
		range(i, 0, n) {
			dfs1(0, -1, i, graph, dp1, s);
		}

		vector<vector<int>> dp2(n, vector<int>(n + 2, 0));
		for (int i = n - 1; i >= 0; i--) {
			dfs2(0, -1, i, graph, dp2, s);
		}

		int res = 0;
		range(i, 0, n) {
			res = max(res, *max_element(dp1[i].begin(), dp1[i].end()));
			res = max(res, *max_element(dp1[i].begin(), dp1[i].end()));
		}

		// range(i, 0, n) {
		// 	arrPrint(dp1[i]);
		// }
		// range(i, 0, n) {
		// 	arrPrint(dp2[i]);
		// }

		range(i, -1, n + 1) {
			res = max(res, dfs3(0, -1, i, graph, dp1, dp2, s));
		}

		print(res);
		// print("debug");
		// cout.flush();
	}
}
