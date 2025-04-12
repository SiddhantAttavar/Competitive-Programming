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

void dfs(int u, int p, vector<vector<int>> &graph, vector<int> &d) {
	for (int v : graph[u]) {
		if (v != p) {
			d[v] = d[u] + 1;
			dfs(v, u, graph, d);
		}
	}
}

void dfs1(int u, int p, vector<vector<int>> &graph, vector<int> &l) {
	if (graph[u].size() == 1 and graph[u][0] == p) {
		l[u] = 0;
		return;
	}
	for (int v : graph[u]) {
		if (v != p) {
			dfs1(v, u, graph, l);
			l[u] = max(l[u], l[v] + 1);
		}
	}
}

void dfs2(int u, int p, int z, vector<vector<int>> &graph, vector<int> &l, vector<int> &d) {
	int x = z, y = -1;
	int a = -1;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}
		if (l[v] + 1 > x) {
			y = x;
			x = l[v] + 1;
			a = v;
		}
		else if (l[v] + 1 > y) {
			y = l[v] + 1;
		}
	}
	d[u] = x;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		if (v == a) {
			dfs2(v, u, y + 1, graph, l, d);
		}
		else {
			dfs2(v, u, x + 1, graph, l, d);
		}
	}
}

int32_t main() {
	setup();

	int n1;
	input(n1);
	vector<vector<int>> g1(n1);
	rep(i, 0, n1 - 1) {
		int u, v;
		input(u, v);
		g1[u - 1].push_back(v - 1);
		g1[v - 1].push_back(u - 1);
	}

	int n2;
	input(n2);
	vector<vector<int>> g2(n2);
	rep(i, 0, n2 - 1) {
		int u, v;
		input(u, v);
		g2[u - 1].push_back(v - 1);
		g2[v - 1].push_back(u - 1);
	}

	vector<int> d(n1, 0);
	dfs(0, -1, g1, d);
	int x = max_element(d.begin(), d.end()) - d.begin();
	d = vector<int>(n1, 0);
	dfs(x, -1, g1, d);
	x = *max_element(d.begin(), d.end());

	d = vector<int>(n2, 0);
	dfs(0, -1, g2, d);
	int y = max_element(d.begin(), d.end()) - d.begin();
	d = vector<int>(n2, 0);
	dfs(y, -1, g2, d);
	y = *max_element(d.begin(), d.end());

	vector<int> l(n1, 0);
	dfs1(0, -1, g1, l);
	vector<int> p(n1);
	dfs2(0, -1, 0, g1, l, p);

	l = vector<int>(n2, 0);
	dfs1(0, -1, g2, l);
	vector<int> q(n2);
	dfs2(0, -1, 0, g2, l, q);

	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	reverse(q.begin(), q.end());

	vector<int> pref(n2 + 1);
	rep(i, 0, n2) {
		pref[i + 1] = pref[i] + q[i];
	}

	int j = 0;
	int res = 0;
	rep(i, 0, n1) {
		while (j < n2 and p[i] + q[j] + 1 > max(x, y)) {
			j++;
		}
		res += (n2 - j) * max(x, y);
		res += j * (p[i] + 1) + pref[j];
	}
	print(res);
}
