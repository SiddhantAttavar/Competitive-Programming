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
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void dfs1(int u, int p, vi &a, vi &s, vi &dp, vector<vi> &graph) {
	bool b = false;
	for (int v : graph[u]) {
		if (v != p) {
			dfs1(v, u, a, s, dp, graph);
			s[u] ^= (dp[v] == 1 or dp[v] == 3) and a[v];
			b |= dp[v] == 3 and a[v];
		}
	}

	if (s[u] ^ a[u] or b) {
		dp[u] |= 1;
	}
	if (p != -1 and s[u] ^ a[p] ^ a[u] or b) {
		dp[u] |= 2;
	}
}

void dfs2(int u, int p, vector<vi> &graph, vi &a, vi &s, vi &dp, vi &res) {
	for (int v : graph[u]) {
		if (v != p and dp[v] == 2) {
			dfs2(v, u, graph, a, s, dp, res);
			s[u] ^= a[v];
		}
	}
	int k = -1;
	if (a[u] ^ s[u]) {
		res.push_back(u + 1);
	}
	else {
		for (int v : graph[u]) {
			if (v != p and dp[v] == 3 and a[v]) {
				dfs2(v, u, graph, a, s, dp, res);
				k = v;
				break;
			}
		}
		res.push_back(u + 1);
	}
	for (int v : graph[u]) {
		if (v != p and (dp[v] == 1 or dp[v] == 3) and v != k) {
			dfs2(v, u, graph, a, s, dp, res);
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n);
		arrput(a);

		vector<vi> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		rep(i, 0, n) {
			a[i] %= 2;
		}

		vector<vi> adj(n);
		vi dp(n, 0), s(n, 0);
		dfs1(0, -1, a, s, dp, graph);

		if (count(all(dp), 0)) {
			print("NO");
			continue;
		}

		print("YES");
		vi res;
		dfs2(0, -1, graph, a, s, dp, res);
		arrprint(res);
	}
}
