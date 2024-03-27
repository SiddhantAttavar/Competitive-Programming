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

void dfs(int u, int p, vector<vector<int>> &graph, vector<int> &h) {
	for (int v : graph[u]) {
		if (v != p) {
			dfs(v, u, graph, h);
			h[u] = max(h[u], h[v] + 1);
		}
	}
}

void dfs2(int u, int p, vector<vector<int>> &graph, vector<int> &h, vector<int> &d) {
	int m1 = 0, m2 = 0;
	for (int v : graph[u]) {
		if (h[v] + 1 > m1) {
			m2 = m1;
			m1 = h[v] + 1;
		}
		else {
			m2 = h[v] + 1;
		}
	}

	for (int v : graph[u]) {
		if (v != p) {
			if (m1 == h[v] + 1) {
				d[v] = m2 + 1;
			}
			else {
				d[v] = m1 + 1;
			}
			dfs2(v, u, graph, h, d);
		}
	}
}

void dfs3(int u, int p, vector<vector<int>> &graph, vector<int> &l) {
	for (int v : graph[u]) {
		if (v != p) {
			l[v] = l[u] + 1;
			dfs3(v, u, graph, l);
		}
	}
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> p(n);
	arrPut(p);

	vector<vector<int>> graph(n);
	range(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> h(n, 1);
	dfs(0, -1, graph, h);

	vector<int> d(n, 0);
	dfs2(0, -1, graph, h, d);

	range(i, 0, n) {
		d[i] = max(d[i], h[i]) - 1;
	}

	arrPrint(d);

	// int u = 0;
	// range(i, 1, n) {
	// 	if ((d[u] + 1) / 2 > (d[i] + 1) / 2) {
	// 		u = i;
	// 	}
	// }
	//
	// vector<int> l(n, 0);
	// dfs3(u, -1, graph, l);
	//
	// int res = 0;
	// range(i, 0, n) {
	// 	res = (res + (p[i] * ((l[i] + 1) / 2))) % MOD;
	// }
	//
	// print(res);
}
