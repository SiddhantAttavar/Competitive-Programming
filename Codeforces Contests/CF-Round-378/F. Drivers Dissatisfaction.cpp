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

#define vi vector<int>
struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void dfs(int u, int p, vector<vector<pair<int, int>>> &graph, vector<vector<int>> &par, vector<vector<int>> &dp, vector<int> &h, vector<int> &w) {
	for (pair<int, int> q : graph[u]) {
		int v, j;
		tie(v, j) = q;
		if (v == p) {
			continue;
		}

		h[v] = h[u] + 1;
		par[v][0] = u;
		dp[v][0] = j;
		rep(i, 1, par[v].size()) {
			if (par[v][i - 1] == -1) {
				break;
			}
			par[v][i] = par[par[v][i - 1]][i - 1];
			if (w[dp[v][i - 1]] > w[dp[par[v][i - 1]][i - 1]]) {
				dp[v][i] = dp[v][i - 1];
			}
			else {
				dp[v][i] = dp[par[v][i - 1]][i - 1];
			}
		}
		// cout << v << ' ' << u << ": ";
		// arrprint(par[v]);

		dfs(v, u, graph, par, dp, h, w);
	}
}

int lca(int u, int v, vector<vector<int>> &par, vector<vector<int>> &dp, vector<int> &h, vector<int> &w) {
	if (h[u] < h[v]) {
		swap(u, v);
	}

	int k = par[0].size();
	int res = -1;
	for (int i = k - 1; i >= 0; i--) {
		if (h[u] - (1 << i) >= h[v]) {
			// print(u, v, h[u], h[v], i, par[u][i]);
			// cout.flush();
			if (res == -1 or w[dp[u][i]] > w[res]) {
				res = dp[u][i];
			}
			u = par[u][i];
		}
	}
	// print(u, v, h[u], h[v]);
	// cout.flush();

	if (u == v) {
		return res;
	}

	for (int i = k - 1; i >= 0; i--) {
		if (par[u][i] != par[v][i]) {
			if (res == -1 or w[dp[u][i]] > w[res]) {
				res = dp[u][i];
			}
			if (w[dp[v][i]] > w[res]) {
				res = dp[v][i];
			}
			u = par[u][i];
			v = par[v][i];
		}
	}


	if (res == -1 or w[dp[u][0]] > w[res]) {
		res = dp[u][0];
	}
	if (w[dp[v][0]] > w[res]) {
		res = dp[v][0];
	}
	return res;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<int> w(m), c(m);
	arrput(w);
	arrput(c);
	
	vector<pair<int, int>> e(m);
	rep(i, 0, m) {
		input(e[i].first, e[i].second);
		e[i].first--;
		e[i].second--;
	}
	vector<pair<int, pair<int, int>>> f(m);
	rep(i, 0, m) {
		f[i] = {i, {e[i].first, e[i].second}};
	}
	sort(f.begin(), f.end(), [&](pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
		return w[a.first] < w[b.first];
	});

	UF d(n);
	vector<vector<pair<int, int>>> graph(n);
	set<int> l;
	for (pair<int, pair<int, int>> p : f) {
		int u, v, i = p.first;
		tie(u, v) = p.second;

		if (d.join(u, v)) {
			l.insert(i);
			graph[u].push_back({v, i});
			graph[v].push_back({u, i});
		}
	}

	int s;
	input(s);

	vector<vector<int>> par(n, vector<int>(20, -1));
	vector<vector<int>> dp(n, vector<int>(20, -1));
	vector<int> h(n, 0);
	dfs(0, -1, graph, par, dp, h, w);

	int x = 0;
	for (int i : l) {
		x += w[i];
	}

	int res = -1;
	int y = x;
	rep(i, 0, m) {
		if (l.count(i)) {
			int z = x - s / c[i];

			if (z < y) {
				y = z;
				res = i;
			}
			continue;
		}

		int z = x + w[i] - w[lca(e[i].first, e[i].second, par, dp, h, w)] - s / c[i];
		if (z < y) {
			y = z;
			res = i;
		}
	}

	print(y);
	if (res != -1 and !l.count(res)) {
		int j = lca(e[res].first, e[res].second, par, dp, h, w);
		l.erase(j);
		l.insert(res);
	}

	if (res != -1) {
		l.erase(res);
		print(res + 1, w[res] - s / c[res]);
	}
	for (int i : l) {
		print(i + 1, w[i]);
	}
}
