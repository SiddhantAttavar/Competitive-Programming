// https://codebreaker.xyz/problem/oranges2
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << "\n";}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << "\n"
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int n, m, q;
const int MAXN = 1e5, MAXE = 3e5, MAXQ = 1e5;
array<int, 3> edges[MAXE];
vector<pair<int, int>> graph[MAXN];
int p[MAXN][20], x[MAXN][20];
int l[MAXN];
int a[MAXN];

struct DSU {
	DSU(int n) {
		fill(a, a + n, -1);
	}

	int find(int u) {
		if (a[u] < 0) {
			return u;
		}
		a[u] = find(a[u]);
		return a[u];
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

void dfs(int u) {
	for (pair<int, int> e : graph[u]) {
		int v, w;
		tie(v, w) = e;
		if (l[v] == -1) {
			l[v] = l[u] + 1;
			p[v][0] = u;
			x[v][0] = w;
			dfs(v);
		}
	}
}

int32_t main() {
	setup();
	input(n, m, q);
	
	range(i, 0, m) {
		input(edges[i][0], edges[i][1], edges[i][2]);
	}
	sort(edges, edges + m, [](array<int, 3> a, array<int, 3> b) {
		return a[2] < b[2];
	});

	DSU d(n);
	int c = n;
	range(i, 0, m) {
		int w = edges[i][2], u = edges[i][0], v = edges[i][1];

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

	range(i, 0, n) {
		fill(p[i], p[i] + h, -1);
		fill(x[i], x[i] + h, -1);
		l[i] = -1;
	}
	l[0] = 0;
	dfs(0);

	range(j, 1, h) {
		range(i, 0, n) {
			if (p[i][j - 1] != -1) {
				p[i][j] = p[p[i][j - 1]][j - 1];
				x[i][j] = max(x[i][j - 1], x[p[i][j - 1]][j - 1]);
			}
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
		
		if (p[u][0] == v) {
			print(x[u][0]);
			continue;
		}

		int res = 0;
		int c = (1 << (h - 1));
		for (int j = h - 1; j >= 0; j--) {
			if (l[u] - c >= l[v]) {
				res = max(res, x[u][j]);
				u = p[u][j];
			}
			c >>= 1;
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
