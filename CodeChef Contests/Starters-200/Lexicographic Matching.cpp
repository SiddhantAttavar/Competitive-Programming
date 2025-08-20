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

int mod_pow(int a, int b) {
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

int get(int l, int x, vector<int> &fact) {
	int res = 0;
	rep(i, 1, l + 1) {
		int c = mod_pow(fact[l - 1], fact[i - 1] * fact[l - i] % MOD);
		res = (res + c * c) % MOD;
	}
	return res;
}

void dfs(int u, vector<vector<pair<int, bool>>> &graph, vector<bool> &vis, vector<int> &l) {
	vis[u] = true;
	for (auto [v, b] : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis, l);
		}
	}
	l.push_back(u);
}

int32_t main() {
	int N = 1e6;
	vector<int> fact(N + 1, 1);
	rep(i, 2, N + 1) {
		fact[i] = fact[i - 1] * i % MOD;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> b(n);
		arrput(b);

		vector<vector<pair<int, bool>>> graph(n + 1);
		stack<int> s;
		s.push(0);
		graph[0].push_back({n, false});
		bool flag = true;
		rep(i, 1, n) {
			if (b[i] > b[i - 1] + 1) {
				flag = false;
				break;
			}

			rep(j, 0, b[i - 1] - b[i] + 1) {
				graph[s.top()].push_back({i, true});
				s.pop();
			}
			if (!s.empty()) {
				graph[i].push_back({s.top(), false});
			}
			else {
				graph[i].push_back({n, false});
			}
			s.push(i);
		}

		vector<vector<pair<int, bool>>> rev_graph(n + 1);
		rep(u, 0, n + 1) {
			for (auto [v, b] : graph[u]) {
				rev_graph[v].push_back({u, b});
				// print(u, v, b);
			}
		}

		if (!flag) {
			print(0);
			continue;
		}

		vector<int> t;
		vector<bool> v(n + 1, false);
		rep(i, 0, n + 1) {
			if (!v[i]) {
				dfs(i, graph, v, t);
			}
		}
		reverse(t.begin(), t.end());

		vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
		for (int u : t) {
			rep(j, 1, k + 1) {
				int x = 1;
				for (auto [v, b] : rev_graph[u]) {
					x = x * dp[v][j - b] % MOD;
				}
				dp[u][j] = (dp[u][j - 1] + x) % MOD;
			}
		}
		// arrprint(t);
		// rep(i, 0, n + 1) {
		// 	rep(j, 1, k + 1) {
		// 		cout << (dp[i][j] - dp[i][j - 1] + MOD) % MOD << ' ';
		// 	}
		// 	cout << endl;
		// }

		print((dp[n][k] - dp[n][k - 1] + MOD) % MOD);
	}
}
