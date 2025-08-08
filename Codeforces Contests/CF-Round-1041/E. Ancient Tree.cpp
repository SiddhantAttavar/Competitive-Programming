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

void dfs1(int u, int p, vector<vector<int>> &graph, vector<int> &s) {
	for (int v : graph[u]) {
		if (v != p) {
			dfs1(v, u, graph, s);
			s[u] += s[v];
		}
	}
}

int dfs2(int u, int p, vector<vector<int>> &graph, vector<int> &w, vector<int> &c, vector<int> &s, set<int> &a) {
	int k = -1;
	for (int v : graph[u]) {
		if ((v != p) and (k == -1 or s[v] > s[k])) {
			k = v;
		}
	}

	if (k == -1) {
		if (c[u]) {
			a.insert(c[u]);
		}
		return 0;
	}

	int x = -1;
	bool flag = false;
	int res = dfs2(k, u, graph, w, c, s, a);
	for (int v : graph[u]) {
		if (v == p or v == k) {
			continue;
		}

		set<int> b;
		res += dfs2(v, u, graph, w, c, s, b);
		for (int i : b) {
			if (!a.count(i)) {
				a.insert(i);
			}
			else if (x == -1) {
				x = i;
			}
			else if (i != x) {
				flag = true;
			}
		}
	}

	if (flag) {
		res += w[u];
	}
	else if (x != -1) {
		if (c[u] == 0) {
			c[u] = x;
		}
		else if (c[u] != x) {
			res += w[u];
		}
	}
	else if (c[u] == 0 and !a.empty()) {
		c[u] = *a.begin();
	}

	if (c[u]) {
		a.insert(c[u]);
	}
	return res;
}

void dfs3(int u, int p, vector<vector<int>> &graph, vector<int> &c) {
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}
		if (c[v] == 0) {
			c[v] = c[u];
		}
		dfs3(v, u, graph, c);
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> w(n), c(n);
		arrput(w);
		arrput(c);
		vector<int> d = c;

		vector<vector<int>> graph(n);
		vector<pair<int, int>> e(n - 1);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);
			e[i] = {u, v};

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<int> s(n, 1);
		dfs1(0, -1, graph, s);

		set<int> a;
		int res = dfs2(0, -1, graph, w, c, s, a);

		if (c[0] == 0) {
			c[0] = 1;
		}
		dfs3(0, -1, graph, c);

		print(res);
		arrprint(c);
		// a.clear();
		// print(dfs2(0, -1, graph, w, c, s, a), res);
		// a.clear();
		// assert(dfs2(0, -1, graph, w, c, s, a) == res);

		// a.clear();
		// if (dfs2(0, -1, graph, w, c, s, a) != res) {
		// 	print(n, k);
		// 	arrprint(w);
		// 	arrprint(d);
		// 	for (auto [u, v] : e) {
		// 		print(u, v);
		// 	}
		// 	return 0;
		// }
	}
}
