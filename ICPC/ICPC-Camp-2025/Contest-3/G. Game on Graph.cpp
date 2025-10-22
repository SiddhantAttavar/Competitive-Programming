#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void dfs2(int u,  vector<vector<int>> &graph, vector<int> &b, vector<bool> &c, vector<bool> &d);

void dfs1(int u,  vector<vector<int>> &graph, vector<int> &a, vector<bool> &c, vector<bool> &d) {
	c[u] = false;
	for (int v : graph[u]) {
		if (d[v]) {
			dfs2(v, graph, a, c, d);
		}
	}
}

void dfs2(int u,  vector<vector<int>> &graph, vector<int> &a, vector<bool> &c, vector<bool> &d) {
	d[u] = false;
	for (int v : graph[u]) {
		a[v]--;
		if (!a[v] and c[v]) {
			dfs1(v, graph, a, c, d);
		}
	}
}

void dfs4(int u,  vector<vector<int>> &graph, vector<int> &b, vector<bool> &e, vector<bool> &f);

void dfs3(int u,  vector<vector<int>> &graph, vector<int> &b, vector<bool> &e, vector<bool> &f) {
	e[u] = true;
	for (int v : graph[u]) {
		if (!f[v]) {
			dfs4(v, graph, b, e, f);
		}
	}
}

void dfs4(int u,  vector<vector<int>> &graph, vector<int> &b, vector<bool> &e, vector<bool> &f) {
	f[u] = true;
	for (int v : graph[u]) {
		b[v]--;
		if (!b[v] and !e[v]) {
			dfs3(v, graph, b, e, f);
		}
	}
}

int32_t main() {
	setup();

	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	int n, m;
	input(n, m);

	vector<vector<int>> graph(n);
	vector<int> a(n), b(n);
	rep(i, 0, m) {
		int u, v;
		input(u, v);

		graph[v - 1].push_back(u - 1);
		a[u - 1]++;
		b[u - 1]++;
	}

	vector<bool> c(n, true), d(n, true);
	rep(i, 0, n) {
		if (!a[i] and c[i]) {
			dfs1(i, graph, a, c, d);
			dfs2(i, graph, a, c, d);
		}
	}
	
	vector<bool> e(n, false), f(n, false);
	rep(i, 0, n) {
		if (!b[i] and !e[i]) {
			dfs3(i, graph, b, e, f);
		}
	}

	rep(i, 0, n) {
		if (c[i]) {
			assert(!e[i]);
			cout << 'D';
		}
		else if (e[i]) {
			cout << 'L';
		}
		else {
			cout << 'W';
		}
	}
	cout << endl;

	rep(i, 0, n) {
		if (d[i]) {
			assert(!f[i]);
			cout << 'D';
		}
		else if (f[i]) {
			cout << 'W';
		}
		else {
			cout << 'L';
		}
	}
	cout << endl;
}
