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

void dfs1(int u, vector<vector<int>> &graph, vector<int> &s) {
	for (int v : graph[u]) {
		dfs1(v, graph, s);
		s[u] += s[v];
	}
}

void dfs2(int u, vector<vector<int>> &graph, set<int> &p, vector<int> &c, vector<int> &s, vector<int> &dp) {
	if (c[u]) {
		p = {c[u]};
		return;
	}

	int w = graph[u][0];
	rep(v, 1, graph[u].size()) {
		if (s[graph[u][v]] > s[w]) {
			w = graph[u][v];
		}
	}

	map<int, int> m;
	int x = 1;
	for (int v : graph[u]) {
		if (v == w) {
			continue;
		}

		set<int> q;
		dfs2(v, graph, q, c, s, dp);
		dp[u] += dp[v] + 1;
		for (int k : q) {
			m[k]++;
			if (m[k] > x) {
				x = m[k];
				p = {k};
			}
			else if (m[k] == x) {
				p.insert(k);
			}
		}
	}

	if (x == 1) {
		dfs2(w, graph, p, c, s, dp);
		set<int> q;
		for (auto [k, v] : m) {
			if (p.count(k)) {
				q.insert(k);
			}
		}
		if (!q.empty()) {
			p = q;
			x = 2;
		}
		else {
			for (auto [k, v] : m) {
				p.insert(k);
			}
		}
	}
	else {
		set<int> q;
		dfs2(w, graph, q, c, s, dp);
		for (auto [k, v] : m) {
			if (v == x - 1 and q.count(k)) {
				p.insert(k);
			}
			else if (v == x and q.count(k)) {
				p = {k};
				x++;
			}
		}
	}
	dp[u] += dp[w] + 1;
	dp[u] -= x;
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<int>> graph(n);
	rep(i, 1, n) {
		int p;
		input(p);
		graph[p - 1].push_back(i);
	}

	vector<int> c(n);
	arrput(c);

	vector<int> s(n, 1);
	dfs1(0, graph, s);

	vector<int> dp(n, 0);
	set<int> p;
	dfs2(0, graph, p, c, s, dp);
	print(dp[0] + 1);
}
