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
const int MOD = (int) 1e9 + 7; //998244353

void remove_par(int u, vector<vector<int>> &graph) {
	for (int v : graph[u]) {
		graph[v].erase(find(graph[v].begin(), graph[v].end(), u));
		remove_par(v, graph);
	}
}

int dfs(int u, vector<vector<int>> &graph, vector<int> &l, vector<int> &c, int t) {
	if (c[u] == -1) {
		if (l[u] < graph[u].size()) {
			int v = graph[u][l[u]];
			l[u]++;
			c[v] = t;
		}

		c[u] = t;
		t++;
	}

	for (int v : graph[u]) {
		t = dfs(v, graph, l, c, t);
	}
	return t;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> graph(n);
		range(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		int u = 0;
		range(i, 0, n) {
			if (graph[i].size() > graph[u].size()) {
				u = i;
			}
		}

		print(graph[u].size());

		remove_par(u, graph);

		vector<int> l(n, 0);
		range(i, 0, graph[u].size()) {
			vector<int> c(n, -1);
			dfs(u, graph, l, c, 1);
			arrPrint(c);
		}
	}
}
