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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void dfs(int u, int p, vector<vector<int>> &graph, vector<int> &l) {
	if (graph[u].size() == 1 and graph[u][0] == p) {
		l[u] = 0;
		return;
	}
	for (int v : graph[u]) {
		if (v != p) {
			dfs(v, u, graph, l);
			l[u] = max(l[u], l[v] + 1);
		}
	}
}

void dfs2(int u, int p, int z, vector<vector<int>> &graph, vector<int> &l, vector<int> &d) {
	int x = z, y = -1;
	int a = -1;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}
		if (l[v] + 1 > x) {
			y = x;
			x = l[v] + 1;
			a = v;
		}
		else if (l[v] + 1 > y) {
			y = l[v] + 1;
		}
	}
	d[u] = x;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		if (v == a) {
			dfs2(v, u, y + 1, graph, l, d);
		}
		else {
			dfs2(v, u, x + 1, graph, l, d);
		}
	}
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> l(n, 0);
	dfs(0, -1, graph, l);

	vector<int> d(n);
	dfs2(0, -1, 0, graph, l, d);
	arrprint(d);
}
