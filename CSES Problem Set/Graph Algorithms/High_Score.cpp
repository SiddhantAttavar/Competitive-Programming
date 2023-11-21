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

void rev_dfs(int u, vector<vector<int>> &rev_graph, vector<bool> &rev_vis) {
	rev_vis[u] = true;
	for (int v : rev_graph[u]) {
		if (!rev_vis[v]) {
			rev_dfs(v, rev_graph, rev_vis);
		}
	}
}

bool dfs(int u, vector<vector<pair<int, int>>> &graph, vector<pair<int, int>> &q, vector<bool> &in_stack, vector<bool> &rev_vis) {
	// print('b', u);
	in_stack[u] = true;
	// arrPrint(in_stack);

	// for (pair<int, int> p : graph[u]) {
	// 	print(u, p.first, p.second);
	// }

	for (pair<int, int> p : graph[u]) {
		int v, w;
		tie(v, w) = p;
		print(u, v, in_stack[v], rev_vis[v]);

		if (q[v].first == -1) {
			q[v] = {u, w};
			if (dfs(v, graph, q, in_stack, rev_vis)) {
				return true;
			}
		}
		else if (in_stack[v] and rev_vis[v]) {
			int x = w;
			int o = u;
			while (o != v) {
				x += q[o].second;
				o = q[o].first;
			}

			print(x);
			if (x < 0) {
				return true;
			}
		}
	}

	// print('d', u);
	// for (pair<int, int> p : graph[u]) {
	// 	cout << p.first << ' ';
	// }
	// cout << endl;
	in_stack[u] = false;
	return false;
}

void dfs1(int u, vector<vector<pair<int, int>>> &graph, vector<bool> &vis) {
	vis[u] = true;
	for (pair<int, int> p : graph[u]) {
		if (!vis[p.first]) {
			dfs1(p.first, graph, vis);
		}
	}
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<pair<int, int>>> graph(n);
	vector<vector<int>> rev_graph(n);
	vector<pair<pair<int, int>, int>> e;
	range(i, 0, m) {
		int u, v, w;
		input(u, v, w);

		graph[u - 1].push_back({v - 1, -w});
		rev_graph[v - 1].push_back(u - 1);
		e.push_back({{u - 1, v - 1}, -w});
	}

	// range(i, 0, n) {
	// 	cout << i << ": ";
	// 	for (pair<int, int> p : graph[i]) {
	// 		cout << p.first << ' ';
	// 	}
	// 	cout << endl;
	// }

	vector<bool> rev_vis(n, false);
	// arrPrint(rev_vis);
	// range(i, 0, n) {
	// 	arrPrint(rev_graph[i]);
	// }
	rev_dfs(n - 1, rev_graph, rev_vis);
	// arrPrint(rev_vis);

	vector<bool> vis(n, false);
	dfs1(0, graph, vis);
	range(i, 0, n) {
		rev_vis[i] = rev_vis[i] and vis[i];
	}

	// vector<bool> in_stack(n, false);
	// vector<pair<int, int>> q(n, {-1, -1});
	// q[0] = {n, -1};
	// if (dfs(0, graph, q, in_stack, rev_vis)) {
	// 	print(-1);
	// 	return 0;
	// }

	// arrPrint(rev_vis);
	// range(i, 0, n) {
	// 	arrPrint(rev_graph[i]);
	// }

	vector<int> d(n, 1e18);
	d[0] = 0;
	range(i, 0, n) {
		for (pair<pair<int, int>, int> p : e) {
			int u, v, w = p.second;
			tie(u, v) = p.first;
			if (rev_vis[u] and rev_vis[v]) {
				d[v] = min(d[v], d[u] + w);
			}
		}
	}
	for (pair<pair<int, int>, int> p : e) {
		int u, v, w = p.second;
		tie(u, v) = p.first;
		if (rev_vis[u] and rev_vis[v]) {
			if (d[u] + w < d[v]) {
				print(-1);
				return 0;
			}
		}
	}

	print(-d[n - 1]);
}
