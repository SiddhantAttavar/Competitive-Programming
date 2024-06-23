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

int t = 0;

int dfs(int u, int p, vector<vector<int>> &graph, vector<int> &vis, vector<int> &disc, vector<int> &low, vector<int> &l) {
	vis[u] = t;
	disc[u] = low[u] = ++t;
	int res = 1;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		if (vis[v]) {
			low[u] = min(low[u], disc[v]);
		}
		else {
			int x = dfs(v, u, graph, vis, disc, low, l);
			res += x;

			low[u] = min(low[u], low[v]);
			if (low[v] > disc[u]) {
				l.push_back(x);
			}
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<int>> graph(n);
		range(i, 0, m) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<int> vis(n, 0), disc(n, -1), low(n, -1);
		t = 0;
		int res = n * (n - 1) / 2;
		vector<int> l;
		dfs(0, -1, graph, vis, disc, low, l);
		// arrPrint(l);
		for (int i : l) {
			// print(i);
			res = min(res, i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
		}
		print(res);
	}
}
