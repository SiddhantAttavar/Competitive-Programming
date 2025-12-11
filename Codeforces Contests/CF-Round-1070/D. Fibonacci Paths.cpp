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
const int MOD = 998244353;

void dfs(int u, vector<bool> &vis, vector<vector<int>> &graph, vector<int> &l) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, vis, graph, l);
		}
	}
	l.push_back(u);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> a(n);
		arrput(a);

		vector<array<int, 3>> e(m);
		rep(i, 0, m) {
			int u, v;
			input(u, v);
			e[i] = {u - 1, v - 1, i};
		}

		vector<vector<int>> graph(m);
		vector<map<int, int>> s(n);
		for (auto [u, v, i] : e) {
			int x = a[u] + a[v];
			if (!s[v].count(x)) {
				s[v][x] = graph.size();
				graph.push_back({});
			}
			graph[i].push_back(s[v][x]);
			if (!s[u].count(a[v])) {
				s[u][a[v]] = graph.size();
				graph.push_back({});
			}
			graph[s[u][a[v]]].push_back(i);
		}

		vector<int> l;
		vector<bool> vis(graph.size(), false);
		rep(i, 0, graph.size()) {
			if (!vis[i]) {
				dfs(i, vis, graph, l);
			}
		}

		int res = 0;
		vector<int> dp(graph.size());
		for (int u : l) {
			for (int v : graph[u]) {
				dp[u] = (dp[u] + dp[v]) % MOD;
			}
			if (u < m) {
				res = (res + dp[u]) % MOD;
			}
			else {
				dp[u] = (dp[u] + 1) % MOD;
			}
		}
		print(res);
	}
}
