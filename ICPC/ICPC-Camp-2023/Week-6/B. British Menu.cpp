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

void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &topo) {
	visited[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v, graph, visited, topo);
		}
	}
	topo.push_back(u);
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<int>> graph(n);
	range(i, 0, m) {
		int a, b;
		input(a, b);

		graph[a - 1].push_back(b - 1);
	}

	vector<bool> visited(n, false);
	vector<int> topo;
	range(i, 0, n) {
		if (!visited[i]) {
			dfs(i, graph, visited, topo);
		}
	}

	vector<int> ind(n);
	range(i, 0, n) {
		ind[topo[i]] = i;
	}

	vector<int> dp(n, 1);
	int res = 0;
	for (int u : topo) {
		for (int v : graph[u]) {
			if (ind[v] > ind[u]) {
				dp[u] = max(dp[u], dp[v] + 1);
			}
		}
		res = max(res, dp[u]);
	}
	print(res);
}
