#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

void dfs1(int u, int p, vector<vector<int>> &graph, vector<int>&l, vector<int> &par) {
	for (int v : graph[u]) {
		if (v != p) {
			l[v] = l[u] + 1;
			par[v] = u;
			dfs1(v, u, graph, l, par);
		}
	}
}

int dfs2(int u, int p, vector<vector<int>> &graph) {
	int res = 0;
	for (int v : graph[u]) {
		if (v != p) {
			res += dfs2(v, u, graph) + 2;
		}
	}
	return res;
}

int dfs3(int u, int p, vector<vector<int>> &graph) {
	int res = 0;
	for (int v : graph[u]) {
		if (v != p) {
			res = max(res, dfs3(v, u, graph) + 1);
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int a, b;
		input(a, b);
		a--;
		b--;

		vector<vector<int>> graph(n);
		range(i, 0, n - 1) {
			int u, v;
			input(u, v);

			u--;
			v--;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		vector<int> l(n, 0), par(n, -1);
		dfs1(a, -1, graph, l, par);
		// arrPrint(par);

		int u = b;
		while (l[u] != l[b] / 2) {
			u = par[u];
		}

		print(dfs2(u, -1, graph) - dfs3(u, -1, graph) + l[b] - l[u]);
	}
}
