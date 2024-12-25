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
#define vi vector<int>

vi l;
vi par_decomp;
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
	for(auto nx : adj[v]) if(nx != p && !vis[nx] && siz[nx] > n
			/2) {
		return centroid(nx, v, n);
	}
	return v;
}
void process(int v) {}
int solve(int v, int p) {
	find_size(v, p);
	int c = centroid(v, p, siz[v]);
	process(c);
	vis[c] = true;
	for(auto nx : adj[c]) if(!vis[nx]) decomp[c].push_back(solve(nx, c));
	return c;
}

void dfs(int u) {
	for (int v : decomp[u]) {
		par_decomp[v] = u;
		dfs(v);
	}
}

void lca(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) {
			continue;
		}

		par[v][0] = u;
		range(j, 1, 20) {
			if (par[v][j - 1] == -1) {
				break;
			}
			par[v][j] = par[par[v][j - 1]][j - 1];
		}

		l[v] = l[u] + 1;
		lca(v, u);
	}
}

int get_lca(int u, int v) {
	if (l[u] < l[v]) {
		swap(u, v);
	}

	for (int j = 19; j >= 0; j--) {
		// print(u, v, j);
		// cout.flush();
		if (l[u] - l[v] >= (1 << j)) {
			u = par[u][j];
		}
	}

	if (u == v) {
		return u;
	}

	for (int j = 19; j >= 0; j--) {
		if (par[u][j] != par[v][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}

int dist(int u, int v) {
	return l[u] + l[v] - 2 * l[get_lca(u, v)];
}

int32_t main() {
    setup();
	int n, m;
	input(n, m);

	adj.resize(n);
	decomp.resize(n);
	siz.resize(n, 0);
	vis.resize(n, false);
	par_decomp.resize(n, -1);
	par.resize(n, vector<int>(20));
	l.resize(n, 0);

	range(i, 0, n - 1) {
		int u, v;
		input(u, v);

		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}

	lca(0, -1);
	dfs(solve(0, 0));

	// range(u, 0, n) {
	// 	cout << u << ": ";
	// 	arrPrint(decomp[u]);
	// }
	// arrPrint(par_decomp);

	vector<int> d(n, 1e18);
	int v = 0;
	while (v != -1) {
		d[v] = dist(0, v);
		v = par_decomp[v];
	}
	// arrPrint(d);

	while (m--) {
		int o, u;
		input(o, u);
		u--;

		if (o == 1) {
			int v = u;
			while (v != -1) {
				// print(u, v);
				// cout.flush();
				d[v] = min(d[v], dist(u, v));
				v = par_decomp[v];
			}
		}
		else {
			int res = d[u];
			int v = u;
			while (v != -1) {
				// print(u, v);
				// cout.flush();
				res= min(res, d[v] + dist(u, v));
				v = par_decomp[v];
			}
			print(res);
		}
	}
}
