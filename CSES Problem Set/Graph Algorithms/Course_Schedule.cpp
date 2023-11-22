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

bool dfs(int u, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &topo, vector<bool> &in_stack) {
	vis[u] = true;
	in_stack[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			if (!dfs(v, graph, vis, topo, in_stack)) {
				return false;
			}
		}
		else if (in_stack[v]) {
			return false;
		}
	}

	topo.push_back(u + 1);
	in_stack[u] = false;
	return true;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<int>> graph(n);
	range(i, 0, m) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
	}

	vector<bool> vis(n, false), in_stack(n, false);
	vector<int> l;
	range(i, 0, n) {
		if (!vis[i]) {
			if (!dfs(i, graph, vis, l, in_stack)) {
				print("IMPOSSIBLE");
				return 0;
			}
		}
	}
	reverse(l.begin(), l.end());

	arrPrint(l);
}
