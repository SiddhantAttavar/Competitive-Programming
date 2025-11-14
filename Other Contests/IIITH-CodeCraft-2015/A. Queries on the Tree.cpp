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

vector<int> par(1e6, -1);
void dfs(int u, int p, vector<vector<int>> &graph, vector<int> &d, vector<int> &a, vector<int> &b, int &c) {
	a[u] = c;
	c++;
	for (int v : graph[u]) {
		if (v != p) {
			d[v] = d[u] + 1;
			par[v] = u;
			dfs(v, u, graph, d, a, b, c);
		}
	}
	b[u] = c;
	c++;
}

int dfs2(int u, int p, vector<vector<int>> &graph, vector<int> &x, vector<int> &l, vector<int> &d) {
	int res = l[d[u]];
	for (int v : graph[u]) {
		if (v != p) {
			res += dfs2(v, u, graph, x, l, d);
		}
	}
	x[u] += res;
	return res;
}

int brute(int u, int p, vector<vector<int>> &graph, vector<int> &d, vector<int> &z) {
	int res = z[d[u]];
	for (int v : graph[u]) {
		if (v != p) {
			res += brute(v, u, graph, d, z);
		}
	}
	return res;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> d(n, 0), a(n), b(n);
	int c = 0;
	dfs(0, -1, graph, d, a, b, c);

	// rep(i, 0, n) {
	// 	print(i + 1, a[i], b[i]);
	// }

	vector<vector<int>> t(n + 1);
	rep(i, 0, n) {
		t[d[i]].push_back(a[i]);
	}
	rep(i, 0, n + 1) {
		sort(t[i].begin(), t[i].end());
	}

	vector<int> l(n + 1, 0), v(n, 0), z(n + 1, 0);
	set<int> w;
	int k = 100;
	while (m--) {
		int o;
		input(o);

		if (o == 1) {
			int x, y;
			input(x, y);

			z[x] += y;
			l[x] += y;
			w.insert(x);

			if (w.size() == k) {
				dfs2(0, -1, graph, v, l, d);
				l.clear();
				l.resize(n + 1, 0);
				w.clear();
			}
		}
		else {
			int u;
			input(u);

			u--;
			int res = v[u];
			for (int x : w) {
				int z = upper_bound(t[x].begin(), t[x].end(), b[u]) - lower_bound(t[x].begin(), t[x].end(), a[u]);
				res += l[x] * z;
			}

			print(res);
			// print(res, brute(u, par[u], graph, d, z));
			// cout.flush();
			// assert(res == brute(u, par[u], graph, d, z));
		}
	}
}
