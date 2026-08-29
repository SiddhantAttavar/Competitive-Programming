#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = (int) 1e9 + 7;

/** @return the block-cut tree of a graph */
vector<vector<int>> biconnected_components(vector<vector<int>> &g,
                                           vector<bool> &is_cutpoint, vector<int> &id) {
	int n = (int)g.size();

	vector<vector<int>> comps;
	vector<int> stk;
	vector<int> num(n);
	vector<int> low(n);

	is_cutpoint.resize(n);

	// Finds the biconnected components
	function<void(int, int, int &)> dfs = [&](int node, int parent, int &timer) {
		num[node] = low[node] = ++timer;
		stk.push_back(node);
		for (int son : g[node]) {
			if (son == parent) { continue; }
			if (num[son]) {
				low[node] = min(low[node], num[son]);
			} else {
				dfs(son, node, timer);
				low[node] = min(low[node], low[son]);
				if (low[son] >= num[node]) {
					is_cutpoint[node] = (num[node] > 1 || num[son] > 2);
					comps.push_back({node});
					while (comps.back().back() != son) {
						comps.back().push_back(stk.back());
						stk.pop_back();
					}
				}
			}
		}
	};

	int timer = 0;
	dfs(0, -1, timer);
	id.resize(n);

	// Build the block-cut tree
	function<vector<vector<int>>()> build_tree = [&]() {
		vector<vector<int>> t;
		int node_id = 0;
		for (int node = 0; node < n; node++) {
			if (is_cutpoint[node]) {
				id[node] = node_id++;
				t.push_back({});
			}
		}

		for (auto &comp : comps) {
			int node = node_id++;
			t.push_back({});
			for (int u : comp)
				if (!is_cutpoint[u]) {
					id[u] = node;
				} else {
					t[node].push_back(id[u]);
					t[id[u]].push_back(node);
				}
		}
		return t;
	};

	return build_tree();
}

void dfs(int u, int p, vector<vi> &tree, vector<vi> &par, vi &d, vi &s, vi &l) {
	d[u] = s[u];
	for (int v : tree[u]) {
		if (v == p) {
			continue;
		}
		l[v] = l[u] + 1;
		par[v][0] = u;
		rep(i, 1, 20) {
			if (par[v][i - 1] != -1) {
				par[v][i] = par[par[v][i - 1]][i - 1]; 
			}
		}
		dfs(v, u, tree, par, d, s, l);
		d[u] += d[v];
	}
}
 
int anc(int u, int k, vector<vi> &par) {
	for (int i = 19; i >= 0; i--) {
		if (k >> i & 1) {
			u = par[u][i];
		}
	}
	return u;
}
 
int lca(int u, int v, vector<vi> &par, vi &l) {
	if (l[u] < l[v]) {
		swap(u, v);
	}
 
	u = anc(u, l[u] - l[v], par);
	if (u == v) {
		return u;
	}
 
	for (int i = 19; i >= 0; i--) {
		if (par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}
 
	return par[u][0];
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vi> graph(n);
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<bool> cutpoint;
	vi comp;
	vector<vi> tree = biconnected_components(graph, cutpoint, comp);

	int t = sz(tree);
	vi s(t, 0);
	rep(i, 0, n) {
		s[comp[i]]++;
	}

	vector<vi> p(t, vi(20, -1));
	vi d(t, 0), l(t, 0);
	dfs(0, -1, tree, p, d, s, l);
	// rep(i, 0, t) {
	// 	cout << i << ": ";
	// 	for (int j : tree[i]) {
	// 		cout << j << ' ';
	// 	}
	// 	cout << endl;
	// }
 
	int q;
	cin >> q;
	while (q--) {
		int i, j;
		cin >> i >> j;
 
		i--;
		j--;
		int u = comp[i], v = comp[j];

		if (u == v) {
			cout << n << endl;
			continue;
		}
 
		int w = lca(u, v, p, l);
		int res = n;
		if (cutpoint[i]) {
			if (w == u) {
				res -= n - d[anc(v, l[v] - l[u] - 1, p)] - 1;
			}
			else {
				res -= d[u] - 1;
			}
		}
		if (cutpoint[j]) {
			if (w == v) {
				res -= n - d[anc(u, l[u] - l[v] - 1, p)] - 1;
			}
			else {
				res -= d[v] - 1;
			}
		}
		cout << res << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
