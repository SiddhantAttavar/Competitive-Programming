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

int N = 2e5, t = 0;
vector<int> l(N, 0), a(N), b(N);
vector<vector<int>> par(N, vector<int>(20, -1));
vector<vector<int>> dp(N, vector<int>(20, 1e18));

void dfs(int u, int p, vector<vector<pair<int, int>>> &graph) {
	a[u] = t++;
	for (pair<int, int> i : graph[u]) {
		int v, w;
		tie(v, w) = i;
		if (v == p) {
			continue;
		}

		l[v] = l[u] + 1;
		par[v][0] = u;
		dp[v][0] = w;
		rep(i, 1, 20) {
			if (par[v][i - 1] == -1) {
				break;
			}
			par[v][i] = par[par[v][i - 1]][i - 1];
			dp[v][i] = min(dp[v][i - 1], dp[par[v][i - 1]][i - 1]);
		}
		dfs(v, u, graph);
	}
	b[u] = t++;
}

pair<int, int> lca(int u, int v) {
	if (u == v) {
		return {u, 1e18};
	}

	if (l[u] < l[v]) {
		swap(u, v);
	}

	int res = 1e18;
	for (int i = 19; i >= 0; i--) {
		if (l[u] - (1 << i) >= l[v]) {
			res = min(res, dp[u][i]);
			u = par[u][i];
		}
	}

	if (u == v) {
		return {u, res};
	}

	for (int i = 19; i >= 0; i--) {
		if (par[u][i] != par[v][i]) {
			res = min({res, dp[u][i], dp[v][i]});
			u = par[u][i];
			v = par[v][i];
		}
	}

	return {par[u][0], min({res, dp[u][0], dp[v][0]})};
}

bool anc(int u, int v) {
	return a[u] <= a[v] and b[u] >= b[v];
}

bool check(int u, int v, int x, int y) {
	int w = lca(u, v).first;
	return anc(w, x) and (anc(x, u) or anc(x, v)) and anc(w, y) and (anc(y, u) or anc(y, v));
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<int>> e(n - 1, vector<int>(3));
	vector<vector<pair<int, int>>> graph(n);
	rep(i, 0, n - 1) {
		int u, v, w;
		input(u, v, w);
		e[i] = {w, u - 1, v - 1};
		graph[u - 1].push_back({v - 1, w});
		graph[v - 1].push_back({u - 1, w});
	}

	dfs(0, -1, graph);

	sort(e.begin(), e.end());

	int res = e[n - 2][0];
	vector<pair<int, int>> c(n - 1, {-1, -1});
	c[n - 2] = {e[n - 2][1], e[n - 2][2]};
	for (int i = n - 3; i >= 0; i--) {
		res = min(res, max(e[n - 2][0] - lca(c[i + 1].first, c[i + 1].second).second, e[i][0]));
		int p = c[i + 1].first, q = c[i + 1].second, r = e[i][1], s = e[i][2];
		if (check(p, q, r, s)) {
			c[i] = {p, q};
		}
		else if (check(p, r, q, s)) {
			c[i] = {p, r};
		}
		else if (check(p, s, q, r)) {
			c[i] = {p, s};
		}
		else if (check(q, r, p, s)) {
			c[i] = {q, r};
		}
		else if (check(q, s, p, r)) {
			c[i] = {q, s};
		}
		else if (check(r, s, p, q)) {
			c[i] = {r, s};
		}
		else {
			break;
		}
	}

	print(res);
}
