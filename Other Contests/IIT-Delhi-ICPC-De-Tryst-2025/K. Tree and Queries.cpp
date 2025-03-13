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
const int MOD = (int) 1e9 + 7; //998244353
#define vi vector<int>

int h = 30;
vi l, d;
vi par_decomp;
vector<vector<pair<int, int>>> anc;
vector<vector<pair<int, int>>> graph;
vector<vi> par;
vector<vi> decomp;
vector<vi> adj; vi siz;
vector<bool> vis;
void find_size(int v, int p) {
	siz[v] = 1;
	for(auto nx : adj[v]) if(nx != p && !vis[nx]) {
		find_size(nx, v);
		siz[v] += siz[nx];
	}
}
int centroid(int v, int p, int n) {
	for(auto nx : adj[v]) if(nx != p && !vis[nx] && siz[nx] > n/2) {
		return centroid(nx, v, n);
	}
	return v;
}
void get_dists(int u, int c, int p = -1, int d = 0) {
	// print(u, c, d);
	for (pair<int, int> i : graph[u]) {
		int v, w;
		tie(v, w) = i;

		if (v == p or vis[v]) {
			continue;
		}

		get_dists(v, c, u, d + w);
	}
	anc[u].push_back({c, d});
}
int solve(int v, int p) {
	find_size(v, p);
	int c = centroid(v, p, siz[v]);
	get_dists(c, c, -1);
	vis[c] = true;
	for(auto nx : adj[c]) if(!vis[nx]) decomp[c].push_back(solve(nx, c));
	return c;
}

void dfs(int u) {
	for (int v : decomp[u]) {
		par_decomp[v] = u;
	}
	for (int v : decomp[u]) {
		dfs(v);
	}
}

void lca(int u, int p) {
	for (pair<int, int> i : graph[u]) {
		int v, w;
		tie(v, w) = i;
		if (v == p) {
			continue;
		}

		par[v][0] = u;
		rep(j, 1, h) {
			if (par[v][j - 1] == -1) {
				break;
			}
			par[v][j] = par[par[v][j - 1]][j - 1];
		}

		l[v] = l[u] + 1;
		d[v] = d[u] + w;
		lca(v, u);
	}
}

int get_lca(int u, int v) {
	if (l[u] < l[v]) {
		swap(u, v);
	}

	for (int j = h - 1; j >= 0; j--) {
		if (l[u] - l[v] >= (1 << j)) {
			u = par[u][j];
		}
	}

	if (u == v) {
		return u;
	}

	for (int j = h - 1; j >= 0; j--) {
		if (par[u][j] != par[v][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}

int dist(int u, int v) {
	return d[u] + d[v] - 2 * d[get_lca(u, v)];
}

int32_t main() {
    setup();
	int n;
	input(n);

	anc.resize(n);
	graph.resize(n);
	adj.resize(n);
	decomp.resize(n);
	siz.resize(n, 0);
	vis.resize(n, false);
	par_decomp.resize(n, -1);
	par.resize(n, vector<int>(h));
	l.resize(n, 0);
	d.resize(n, 0);

	rep(i, 0, n - 1) {
		int u, v, w;
		input(u, v, w);

		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
		
		graph[u - 1].push_back({v - 1, w});
		graph[v - 1].push_back({u - 1, w});
	}

	lca(0, -1);
	dfs(solve(0, 0));

	vector<int> d(n, 1e16);

	// rep(i, 0, n) {
	// 	// print(i, anc[i].size());
	// 	// for (pair<int, int> p : anc[i]) {
	// 	// 	cout << p.first << ',' << p.second << ' ';
	// 	// }
	// 	// cout << endl;
	// }

	// arrprint(par_decomp);

	int q;
	input(q);
	while (q--) {
		int a, b;
		input(a, b);

		vector<int> s(a), t(b);
		arrput(s);
		arrput(t);

		vector<int> l;
		for (int u : s) {
			for (pair<int, int> p : anc[u - 1]) {
				l.push_back(p.first);
				d[p.first] = min(d[p.first], p.second);
			}
		}

		int res = 1e16;
		for (int u : t) {
			for (pair<int, int> p : anc[u - 1]) {
				l.push_back(p.first);
				// print(u, p.first, p.second, d[p.first]);
				res = min(res, p.second + d[p.first]);
			}
		}
		print(res);

		for (int v : l) {
			d[v] = 1e16;
		}
	}
}
