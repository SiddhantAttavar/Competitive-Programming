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

void dfs(int u, vector<vector<int>> &graph, vector<bool> &v, vector<int> &l) {
	v[u] = true;
	for (int i : graph[u]) {
		if (!v[i]) {
			dfs(i, graph, v, l);
		}
	}
	l.push_back(u);
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<int>> graph(n), rev_graph(n);
	range(i, 0, m) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		rev_graph[v - 1].push_back(u - 1);
	}

	vector<bool> v(n, false);
	vector<int> l;
	dfs(0, graph, v, l);
	reverse(l.begin(), l.end());
	// arrPrint(l);

	vector<int> dp(n, -1e18);
	vector<int> p(n, -1);
	dp[0] = 0;
	for (int i : l) {
		for (int j : rev_graph[i]) {
			if (dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				p[i] = j;
			}
		}
	}

	if (dp[n - 1] < 0) {
		print("IMPOSSIBLE");
	}
	else {
		print(dp[n - 1] + 1);
		int u = n - 1;
		vector<int> res = {n};
		while (u) {
			u = p[u];
			res.push_back(u + 1);
		}
		reverse(res.begin(), res.end());
		arrPrint(res);
	}
}
