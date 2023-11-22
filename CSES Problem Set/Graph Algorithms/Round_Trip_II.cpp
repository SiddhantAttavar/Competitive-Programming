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

bool dfs(int u, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &p, vector<bool> &inStack) {
	vis[u] = true;
	inStack[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			p[v] = u;
			if (dfs(v, graph, vis, p, inStack)) {
				return true;
			}
		}
		else if (inStack[v]) {
			vector<int> res = {v + 1, u + 1};
			while (u != v) {
				u = p[u];
				res.push_back(u + 1);
			}
			print(res.size());
			reverse(res.begin(), res.end());
			arrPrint(res);
			return true;
		}
	}

	inStack[u] = false;
	return false;
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

	vector<bool> vis(n, false);
	vector<int> p(n, -1);
	vector<bool> inStack(n, false);
	range(i, 1, n) {
		if (!vis[i]) {
			if (dfs(i, graph, vis, p, inStack)) {
				return 0;
			}
		}
	}

	print("IMPOSSIBLE");
}
