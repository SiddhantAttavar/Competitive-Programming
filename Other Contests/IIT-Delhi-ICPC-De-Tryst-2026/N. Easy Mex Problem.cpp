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

const int N = 5e5;
vi fact(N + 1, 1), inv_fact(N + 1, 1);

int mpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int mdiv(int a, int b) {
	return a * mpow(b, MOD - 2) % MOD;
}

void dfs1(int u, int p, vector<vi> &graph, vi &s) {
	for (int v : graph[u]) {
		if (v != p) {
			dfs1(v, u, graph, s);
			s[u] += s[v];
		}
	}
}

void dfs2(int u, int p, vector<vi> &graph, vi &dp, vi &s) {
	for (int v : graph[u]) {
		if (v != p) {
			dp[v] = dp[u] * mdiv(s[v], sz(graph) - s[v]) % MOD;
			dfs2(v, u, graph, dp, s);
		}
	}
}

int32_t main() {
	rep(i, 2, N + 1) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	inv_fact[N] = mdiv(1, fact[N]);
	for (int i = N - 1; i >= 0; i--) {
		inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vi> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vi dp(n, 1), s(n, 1);
		dfs1(0, -1, graph, s);
		dp[0] = fact[n];
		rep(i, 0, n) {
			dp[0] = mdiv(dp[0], s[i]);
		}
		dfs2(0, -1, graph, dp, s);
		print(accumulate(all(dp), 0ll) % MOD);
	}
}
