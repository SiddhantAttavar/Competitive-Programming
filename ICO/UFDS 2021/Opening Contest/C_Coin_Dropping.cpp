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

vector<int> dp1, dp2;
vector<vector<int>> graph;

int dfs(int u, bool b) {
	if (b) {
		if (dp1[u] != -1) {
			return dp1[u];
		}

		if (graph[u].size() < 1) {
			return dp1[u] = u;
		}

		if (graph[graph[u][0]][0] == u) {
			return dp1[u] = dfs(graph[u][0], false);
		}
		return dp1[u] = dfs(graph[u][0], true);
	}
	else {
		if (dp2[u] != -1) {
			return dp2[u];
		}

		if (graph[u].size() < 2) {
			return dp2[u] = u;
		}

		if (graph[graph[u][1]][0] == u) {
			return dp2[u] = dfs(graph[u][1], false);
		}
		return dp2[u] = dfs(graph[u][1], true);
	}
}

int32_t main() {
	setup();
	
	int n;
	input(n);

	dp1.resize(n, -1);
	dp2.resize(n, -1);
	graph.resize(n);

	range(i, 0, n - 1) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	range(i, 0, n) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	range(i, 0, n) {
		print(dfs(i, true) + 1);
	}
}
