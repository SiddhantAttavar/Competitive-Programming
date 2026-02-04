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
const int MOD = 998244353;

bool dfs1(int u, int p, vector<vi> &graph, vi &b, vi &l) {
	if (u == sz(graph) - 1) {
		b[u] = true;
		l.push_back(u);
		return true;
	}
	for (int v : graph[u]) {
		if (v != p) {
			b[u] |= dfs1(v, u, graph, b, l);
		}
	}
	if (b[u]) {
		l.push_back(u);
	}
	return b[u];
}

int dfs2(int u, int p, vector<vi> &graph, vi &b) {
	int res = 1;
	for (int v : graph[u]) {
		if (v != p and !b[v]) {
			res += dfs2(v, u, graph, b);
		}
	}
	return res;
}

int32_t main() {
	const int N = 2e5;
	vi fact(N + 1, 1);
	rep(i, 2, N + 1) {
		fact[i] = fact[i - 1] * i % MOD;
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

		vi b(n, false), l;
		dfs1(0, -1, graph, b, l);

		vi a;
		reverse(all(l));
		for (int i : l) {
			a.push_back(dfs2(i, -1, graph, b));
		}
		a.back() = 1;

		vi dp(sz(a));
		dp[0] = a[0];
		dp[1] = a[1] * dp[0] + (l[1] != n - 1);
		rep(i, 2, sz(l)) {
			dp[i] = a[i] * dp[i - 1] % MOD;
			if (i != sz(l) - 1) {
				dp[i] = (dp[i] + dp[i - 2]) % MOD;
			}
		}
		print(dp.back());
	}
}
