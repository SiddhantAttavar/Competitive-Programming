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

void topo_sort(int u, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &topo) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			topo_sort(v, graph, vis, topo);
		}
	}
	topo.push_back(u);
}

void dfs(int u, vector<vector<int>> &graph, vector<int> &comp, int x) {
	comp[u] = x;
	for (int v : graph[u]) {
		if (comp[v] == -1) {
			dfs(v, graph, comp, x);
		}
	}
}

int flip(int x, int m) {
	return 2 * m - x - 1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> a(3, vector<int>(n));
		range(i, 0, 3) {
			arrPut(a[i]);
		}

		vector<vector<int>> graph(2 * n), rev_graph(2 * n);
		range(i, 0, n) {
			int u = abs(a[0][i]) - 1;
			int v = abs(a[1][i]) - 1;
			int w = abs(a[2][i]) - 1;

			if (a[0][i] < 0) {
				u = flip(u, n);
			}
			if (a[1][i] < 0) {
				v = flip(v, n);
			}
			if (a[2][i] < 0) {
				w = flip(w, n);
			}

			graph[flip(u, n)].push_back(v);
			graph[flip(u, n)].push_back(w);
			graph[flip(v, n)].push_back(u);
			graph[flip(v, n)].push_back(w);
			graph[flip(w, n)].push_back(u);
			graph[flip(w, n)].push_back(v);

			rev_graph[u].push_back(flip(v, n));
			rev_graph[u].push_back(flip(w, n));
			rev_graph[v].push_back(flip(u, n));
			rev_graph[v].push_back(flip(w, n));
			rev_graph[w].push_back(flip(u, n));
			rev_graph[w].push_back(flip(v, n));
		}

		vector<bool> vis(2 * n, false);
		vector<int> topo;
		range(i, 0, 2 * n) {
			if (!vis[i]) {
				topo_sort(i, graph, vis, topo);
			}
		}
		reverse(topo.begin(), topo.end());

		vector<int> comp(2 * n, -1);
		int x = 0;
		for (int i : topo) {
			if (comp[i] == -1) {
				dfs(i, rev_graph, comp, x);
				x++;
			}
		}

		bool flag = true;
		range(i, 0, n) {
			if (comp[i] == comp[flip(i, n)]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
