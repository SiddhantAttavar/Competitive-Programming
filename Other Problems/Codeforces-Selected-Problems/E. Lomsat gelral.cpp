#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void dfs1(int u, int p, vector<vector<int>> &graph, vector<int> &s, vector<int> &m) {
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		dfs1(v, u, graph, s, m);
		s[u] += s[v];
		if (m[u] == -1 or s[v] > s[m[u]]) {
			m[u] = v;
		}
	}
}

void dfs2(int u, int p, vector<vector<int>> &graph, vector<int> &res, vector<int> &m, map<int, int> &a, map<int, int> &x, vector<int> &c) {
	if (m[u] != -1) {
		dfs2(m[u], u, graph, res, m, a, x, c);
	}
	x[a[c[u]]] -= c[u];
	a[c[u]]++;
	x[a[c[u]]] += c[u];
	for (int v : graph[u]) {
		if (v == p or v == m[u]) {
			continue;
		}

		map<int, int> b, y;
		dfs2(v, u, graph, res, m, b, y, c);
		for (pair<int, int> p : b) {
			x[a[p.first]] -= p.first;
			a[p.first] += p.second;
			x[a[p.first]] += p.first;
		}
	}
	res[u] = x.rbegin()->second;
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> c(n);
	arrput(c);

	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> s(n, 1), m(n, -1);
	dfs1(0, -1, graph, s, m);

	vector<int> res(n);
	map<int, int> a, x;
	dfs2(0, -1, graph, res, m, a, x, c);
	arrprint(res);
}
