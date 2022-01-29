// https://codebreaker.xyz/problem/oranges2
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

struct DSU {
	vector<int> a;

	DSU(int n) {
		a.resize(n, -1);
	}

	int find(int u) {
		if (a[u] < 0) {
			return u;
		}
		return a[u] = find(a[u]);
	}

	bool unite(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v) {
			return false;
		}

		if (a[u] > a[v]) {
			swap(u, v);
		}

		a[u] += a[v];
		a[v] = u;
		return true;
	}
};

void dfs(vector<vector<pair<int, int>>> &graph, vector<int> &l, vector<vector<int>> &p, vector<vector<int>> &x, int u) {
	for (pair<int, int> e : graph[u]) {
		int v, w;
		tie(v, w) = e;
		if (l[v] == -1) {
			l[v] = l[u] + 1;
			x[v][0] = w;
			p[v][0] = u;
			range(i, 1, p[v].size()) {
				if (p[v][i - 1] == -1) {
					break;
				}
				p[v][i] = p[p[v][i - 1]][i - 1];
			
			dfs(graph, l, p, x, v);
		}
	}
}

int32_t main() {
	setup();
	
	int n, m, q;
	input(n, m, q);
	
	vector<tuple<int, int, int>> edges(m);
	range(i, 0, m) {
		int u, v, w;
		input(u, v, w);
		edges[i] = {w, u, v};
	}
	sort(edges.begin(), edges.end());

	DSU d(n);
	int c = n;
	vector<vector<pair<int, int>>> graph(n);
	for (tuple<int, int, int> t : edges) {
		int w, u, v;
		tie(w, u, v) = t;

		if (d.unite(u, v)) {
			graph[u].push_back({v, w});
			graph[v].push_back({u, w});

			c--;
			if (c == 1) {
				break;
			}
		}
	}

	int h = 0;
	while ((1 << h) <= n) {
		h++;
	}

	vector<vector<int>> p(n, vector<int>(h, -1)), x(n, vector<int>(h));
	vector<int> l(n, -1);
	l[0] = 0;
	dfs(graph, l, p, x, 0);
	
	range(i, 0, n) {
		range(j, 1, h) {
			if (p[i][j - 1] == -1) {
				break;
			}
			x[i][j] = max(x[i][j - 1], x[p[i][j - 1]][j - 1]);
		}
	}

	while (q--) {
		int u, v;
		input(u, v);
		
		if (u == v) {
			print(0);
			continue;
		}

		if (l[u] < l[v]) {
			swap(u, v);
		}

		int res = 0;
		for (int j = h - 1; j >= 0; j--) {
			if (l[u] - (1 << j) >= l[v]) {
				res = max(res, x[u][j]);
				u = p[u][j];
			}
		}

		if (u == v) {
			print(res);
			continue;
		}

		for (int j = h - 1; j >= 0; j--) {
			if (p[u][j] != p[v][j]) {
				res = max({res, x[u][j], x[v][j]});
				u = p[u][j];
				v = p[v][j];
			}
			if (p[u][0] == p[v][0]) {
				break;
			}
		}
		if (u != v) {
			res = max(res, x[u][0]);
			res = max(res, x[v][0]);
		}

		print(res);
	}
}

