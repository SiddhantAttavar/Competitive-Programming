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

void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis);
		}
	}
}

struct DSU {
	vector<int> a;

	DSU(int n) {
		a.resize(n, -1);
	}

	int get(int x) {
		if (a[x] < 0) {
			return x;
		}
		return a[x] = get(a[x]);
	}

	bool unite(int x, int y) {
		x = get(x);
		y = get(y);

		if (x == y) {
			return false;
		}

		if (a[x] > a[y]) {
			swap(x, y);
		}

		a[x] += a[y];
		a[y] = x;
		return true;
	}
};

int32_t main() {
	setup();

	int n, m, d;
	input(n, m, d);

	vector<vector<int>> graph(n);
	range(i, 0, m) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	if (graph[0].size() < d) {
		print("NO");
		return 0;
	}

	vector<bool> vis(n, false);
	vis[0] = true;
	vector<int> a, b;
	for (int u : graph[0]) {
		if (vis[u]) {
			b.push_back(u);
			continue;
		}

		a.push_back(u);
		dfs(u, graph, vis);
	}

	if (a.size() > d) {
		print("NO");
		return 0;
	}

	while (a.size() < d) {
		a.push_back(b.back());
		b.pop_back();
	}

	DSU dsu(n);
	vector<pair<int, int>> res;
	for (int i : a) {
		dsu.unite(0, i);
		res.push_back({1, i + 1});
	}

	range(u, 1, n) {
		for (int v : graph[u]) {
			if (v and dsu.unite(u, v)) {
				res.push_back({u + 1, v + 1});
			}
		}
	}

	print("YES");
	for (pair<int, int> p : res) {
		print(p.first, p.second);
	}
}
