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

void dfs1(int u, int p, vector<vector<int>> &graph, int m, vector<int> &a) {
	a[u] = 1;
	for (int v : graph[u]) {
		if (v != p) {
			dfs1(v, u, graph, m, a);
			a[u] = a[u] * (a[v] + 1) % m;
		}
	}
}

void dfs2(int u, int p, vector<vector<int>> &graph, int m, vector<int> &a, vector<int> &dp, int k) {
	vector<int> b;
	for (int v : graph[u]) {
		if (v != p) {
			b.push_back(a[v]);
		}
	}

	vector<int> x(b.size() + 1, 1), y(b.size() + 1, 1);
	rep(i, 0, b.size()) {
		x[i + 1] = x[i] * (b[i] + 1) % m;
	}
	for (int i = b.size() - 1; i >= 0; i--) {
		y[i] = y[i + 1] * (b[i] + 1) % m;
	}

	int i = 0;
	for (int v : graph[u]) {
		if (v != p) {
			int z = (k + 1) * x[i] % m * y[i + 1] % m;
			dp[v] = a[v] * (z + 1) % m;
			dfs2(v, u, graph, m, a, dp, z);
			i++;
		}
	}
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

	vector<int> a(n), dp(n);
	dfs1(0, -1, graph, m, a);
	dp[0] = a[0];
	dfs2(0, -1, graph, m, a, dp, 0);
	for (int i : dp) {
		print(i);
	}
}
