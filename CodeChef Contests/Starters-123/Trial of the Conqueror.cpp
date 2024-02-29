#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

void dfs1(int u, int p, vector<vector<int>> &graph, vector<vector<int>> &par, vector<int> &a, vector<int> &l, int k) {
	if (graph[u].size() == 1 and p != -1) {
		l[u] = 0;
	}

	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		par[v][0] = u;
		range(j, 0, 19) {
			if (par[v][j] == -1) {
				break;
			}
			par[v][j + 1] = par[par[v][j]][j];
		}

		dfs1(v, u, graph, par, a, l, k);
		l[u] = min(l[u], l[v] + 1);
	}
}

void dfs2(int u, int p, vector<vector<int>> &graph, vector<int> &a, vector<int> &l, vector<int> &s, int k) {
	if (l[u] == 0) {
		s[u] = 1;
	}

	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		dfs2(v, u, graph, a, l, s, k);
		if (l[v] < k) {
			s[u] += s[v];
		}
	}
}

int dfs3(int u, int p, vector<vector<int>> &graph, vector<int> &a, vector<int> &l, vector<int> &s, int k) {
	int res = l[u] == 0, y = 0;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		int x = dfs3(v, u, graph, a, l, s, k);
		if (l[v] < k) {
			res += s[v];
			y = max(y, x - s[v]);
		}
		else {
			y = max(y, x);
		}
	}

	// print(u, res, y);
	return res + y;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<vector<int>> graph(n);
		range(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<vector<int>> p(n, vector<int>(20, -1));
		vector<int> a(n, 0), l(n, 1e9), s(n, 0);
		
		dfs1(0, -1, graph, p, a, l, k);
		dfs2(0, -1, graph, a, l, s, k);
		// arrPrint(s);
		print(dfs3(0, -1, graph, a, l, s, k));
	}
}
