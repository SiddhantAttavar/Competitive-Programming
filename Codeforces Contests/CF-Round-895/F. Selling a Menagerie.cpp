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

void dfs(int u, vector<vector<int>> &graph, vector<vector<int>> &comp, vector<bool> &visited) {
	visited[u] = true;
	comp.back().push_back(u);
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v, graph, comp, visited);
		}
	}
}

void dfs2(int u, vector<int> &a, vector<int> &topo, vector<bool> &visited) {
	visited[u] = true;
	if (!visited[a[u]]) {
		dfs2(a[u], a, topo, visited);
	}
	topo.push_back(u);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		vector<int> c(n);
		arrPut(c);

		range(i, 0, n) {
			a[i]--;
		}

		vector<vector<int>> graph(n);
		vector<vector<int>> comps;
		vector<bool> visited(n, false);
		range(i, 0, n) {
			graph[i].push_back(a[i]);
			graph[a[i]].push_back(i);
		}

		range(i, 0, n) {
			if (!visited[i]) {
				comps.push_back({});
				dfs(i, graph, comps, visited);
			}
		}

		vector<int> res;
		vector<int> inCycle(n, false);
		fill(visited.begin(), visited.end(), false);
		for (vector<int> comp : comps) {
			int u = comp[0];
			while (!visited[a[u]]) {
				visited[u] = true;
				u = a[u];
			}

			int v = a[u];
			inCycle[u] = true;
			vector<int> cycle = {u};
			while (v != u) {
				inCycle[v] = true;
				cycle.push_back(v);
				v = a[v];
			}

			vector<int> topo;
			fill(visited.begin(), visited.end(), false);
			for (int i : cycle) {
				visited[i] = true;
			}
			for (int i : comp) {
				if (!visited[i]) {
					dfs2(i, a, topo, visited);
				}
			}
			reverse(topo.begin(), topo.end());
			for (int i : topo) {
				res.push_back(i);
			}

			int k = cycle.size();

			int m = 0;
			range(i, 1, k) {
				if (c[cycle[m]] > c[cycle[i]]) {
					m = i;
				}
			}

			range(i, m + 1, k) {
				res.push_back(cycle[i]);
			}
			range(i, 0, m + 1) {
				res.push_back(cycle[i]);
			}
		}

		range(i, 0, n) {
			res[i]++;
		}
		arrPrint(res);
	}
}
