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

void dfs(int u, int p, int &c, vector<vector<int>> &graph, vector<int> &ti, vector<int> &to) {
	ti[u] = c++;
	for (int v : graph[u]) {
		if (v != p) {
			dfs(v, u, c, graph, ti, to);
		}
	}
	to[u] = c - 1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s;
		input(s);

		vector<vector<int>> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<int> ti(n, 0), to(n, 0);
		int c = 1;
		dfs(0, -1, c, graph, ti, to);

		vector<int> l(n);
		rep(i, 0, n) {
			l[ti[i] - 1] = i;
		}

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				int u = l[i], v = l[j], x = 0;
				if (s[u] == s[v]) {
					x = (1 + dp[ti[u]][ti[v]] - dp[ti[u]][to[v]] - dp[to[u]][ti[v]] + dp[to[u]][to[v]] + 2 * MOD) % MOD;
				}
				dp[i][j] = (x + dp[i][j + 1] + dp[i + 1][j] - dp[i + 1][j + 1] + MOD) % MOD;
			}
		}
		rep(i, 0, n) {
			int l = ti[i] - 1, r = to[i];
			cout << (dp[l][l] - dp[l][r] - dp[r][l] + dp[r][r] + 2 * MOD) % MOD << ' ';
		}
		cout << endl;
	}
}
