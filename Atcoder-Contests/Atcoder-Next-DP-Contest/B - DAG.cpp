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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = 998244353;

void dfs(int u, vector<vi> &graph, vi &b, vi &t) {
	b[u] = true;
	for (int v : graph[u]) {
		if (!b[v]) {
			dfs(v, graph, b, t);
		}
	}
	t.push_back(u);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vi> graph(n);
		rep(i, 0, m) {
			int u, v;
			input(u, v);
			graph[u - 1].push_back(v - 1);
		}

		vi t, b(n, false);
		rep(i, 0, n) {
			if (!b[i]) {
				dfs(i, graph, b, t);
			}
		}

		vi dp(n, 0);
		dp[n - 1] = 1;
		for (int u : t) {
			for (int v : graph[u]) {
				dp[u] = (dp[u] + dp[v]) % MOD;
			}
		}
		print(dp[0]);
	}
}
