// https://codebreaker.xyz/problem/car
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
// #define int long long

vector<vector<pair<int, int>>> graph;

struct DSU {
	vector<int> a;

	DSU(int n) {
		a.resize(n, -1);
	}

	int find(int x) {
		if (a[x] < 0) {
			return x;
		}
		return a[x] = find(a[x]);
	}

	bool unite(int x, int y) {
		x = find(x);
		y = find(y);
		
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

pair<bool, int> dfs(int u, int p, int e) {
	int res = 0;
	if (u == e) {
		return {true, 0};
	}
	for (pair<int, int> k : graph[u]) {
		int v, w;
		tie(v, w) = k;
		if (v != p) {
			pair<bool, int> x = dfs(v, u, e);
			if (x.first) {
				res = max({
					res,
					w,
					x.second
				});
				return {true, res};
			}
		}
	}
	return {false, 0};
}

int32_t main() {
	setup();
	
	int n, e;
	input(n, e);

	vector<tuple<int, int, int>> edges;
	while (e--) {
		int u, v, w;
		input(u, v, w);
		edges.push_back({u, v, w});
	}
	
	sort(edges.begin(), edges.end(), [](tuple<int, int, int> x, tuple<int, int, int> y) {
		return get<2>(x) < get<2>(y);
	});
	
	DSU dsu(n);
	graph.resize(n);
	for (tuple<int, int, int> t : edges) {
		int u, v, w;
		tie(u, v, w) = t;
		if (dsu.unite(u - 1, v - 1)) {
			graph[u - 1].push_back({v - 1, w});
			graph[v - 1].push_back({u - 1, w});
		}
	}
	dsu.a.clear();
	edges.clear();
	
	print(dfs(0, -1, n - 1).second);
}
