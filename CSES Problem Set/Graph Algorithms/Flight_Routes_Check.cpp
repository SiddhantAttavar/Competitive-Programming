#include <algorithm>
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

void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis);
		}
	}
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

	vector<bool> vis(n, false), rev_vis(n, false);
	dfs(0, graph, vis);
	dfs(0, rev_graph, rev_vis);

	range(i, 0, n) {
		if (!vis[i]) {
			print("NO");
			print(1, i + 1);
			return 0;
		}
		else if (!rev_vis[i]) {
			print("NO");
			print(i + 1, 1);
			return 0;
		}
	}

	print("YES");
}
