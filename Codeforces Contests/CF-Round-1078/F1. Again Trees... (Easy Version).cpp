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
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

void insert(int x, vi &d) {
	if (!x) {
		return;
	}
	rep(i, 0, sz(d)) {
		int u = 63 - __builtin_clzll(d[i]), v = 63 - __builtin_clzll(x);
		if (u > v) {
			continue;
		}
		if (u < v) {
			d.insert(d.begin() + i, x);
			return;
		}
		x ^= d[i];
		if (!x) {
			return;
		}
	}
	d.push_back(x);
}

int get(int x, vi &d) {
	if (!x) {
		return 0;
	}
	int res = 0;
	rep(i, 0, sz(d)) {
		int u = 63 - __builtin_clzll(d[i]), v = 63 - __builtin_clzll(x);
		if (u > v) {
			continue;
		}
		if (u < v) {
			return -1;
		}
		x ^= d[i];
		res |= 1ll << i;
		if (!x) {
			return res;
		}
	}
	return -1;
}

void dfs(int u, int p, vector<vi> &graph, vi &a, vi &s, vi &d, vector<vi> &dp, vi &b) {
	dp[u][0] = 1;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		dfs(v, u, graph, a, s, d, dp, b);
		s[u] ^= s[v];

		vi ndp(sz(dp[u]), 0);
		rep(i, 0, sz(dp[u])) {
			rep(j, 0, sz(dp[v])) {
				ndp[i ^ j] = (ndp[i ^ j] + dp[u][i] * dp[v][j]) % MOD;
			}
		}
		int x = get(s[v], d);
		if (x == -1) {
			dp[u] = ndp;
			continue;
		}

		rep(i, 0, sz(dp[u])) {
			for (int j : b) {
				ndp[i ^ x] = (ndp[i ^ x] + dp[u][i] * dp[v][x ^ j]) % MOD;
			}
		}
		dp[u] = ndp;
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<vi> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vi a(n), b(k);
		arrput(a);
		arrput(b);

		vi d;
		for (int i : b) {
			insert(i, d);
		}

		vi s = a;
		vector<vi> dp(n, vi(1ll << sz(d), 0));
		set<int> t;
		rep(i, 0, k) {
			b[i] = get(b[i], d);
		}
		dfs(0, -1, graph, a, s, d, dp, b);

		int x = get(s[0], d);
		if (x == -1) {
			print(0);
			continue;
		}

		int res = 0;
		for (int j : b) {
			res = (res + dp[0][x ^ j]) % MOD;
		}
		print(res);
	}
}
