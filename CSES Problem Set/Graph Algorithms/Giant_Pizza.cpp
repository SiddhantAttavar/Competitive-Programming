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
	setup();

	int n, m;
	input(n, m);

	vector<vector<int>> graph(2 * m), rev_graph(2 * m);
	range(i, 0, n) {
		char p, q;
		int x, y;
		input(p, x, q, y);

		x--;
		y--;

		if (p == '-') {
			x = flip(x, m);
		}
		if (q == '-') {
			y = flip(y, m);
		}

		graph[flip(x, m)].push_back(y);
		graph[flip(y, m)].push_back(x);
		rev_graph[y].push_back(flip(x, m));
		rev_graph[x].push_back(flip(y, m));
	}
	
	// range(i, 0, 2 * m) {
	// 	arrPrint(graph[i]);
	// }
	// range(i, 0, 2 * m) {
	// 	arrPrint(rev_graph[i]);
	// }

	vector<bool> vis(2 * m, false);
	vector<int> topo;
	range(i, 0, 2 * m) {
		if (!vis[i]) {
			topo_sort(i, graph, vis, topo);
		}
	}
	reverse(topo.begin(), topo.end());
	// arrPrint(topo);

	vector<int> comp(2 * m, -1);
	int x = 0;
	for (int i : topo) {
		if (comp[i] == -1) {
			dfs(i, rev_graph, comp, x);
			x++;
		}
	}

	// arrPrint(comp);

	vector<char> res(m);
	range(i, 0, m) {
		if (comp[i] == comp[flip(i, m)]) {
			print("IMPOSSIBLE");
			return 0;
		}

		if (comp[i] > comp[flip(i, m)]) {
			res[i] = '+';
		}
		else {
			res[i] = '-';
		}
	}

	arrPrint(res);
}
