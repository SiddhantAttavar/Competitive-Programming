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

bool dfs(int u, vector<vector<int>> &graph, vector<int> &c, int x) {
	c[u] = x;
	for (int v : graph[u]) {
		if ((c[v] == -1 and !dfs(v, graph, c, 1 - x)) or c[v] == c[u]) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	int N = 2e5;
	vector<int> fact(N + 1);
	fact[0] = 1;
	rep(i, 1, N + 1) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<int>> graph(n);
		rep(i, 0, m) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<int> c(n, -1);
		if (!dfs(0, graph, c, 0)) {
			print(0);
			continue;
		}

		int x = accumulate(c.begin(), c.end(), 0ll);
		if (x == 1 or x == n - 1) {
			print(fact[n - 1] * 2 % MOD);
			continue;
		}

		vector<vector<int>> adj(n);
		rep(u, 0, n) {
			if (graph[u].size() == 1) {
				continue;
			}

			for (int v : graph[u]) {
				if (graph[v].size() > 1) {
					adj[u].push_back(v);
				}
			}
		}

		int u = -1;
		rep(i, 0, n) {
			if (adj[i].size() == 1) {
				u = i;
				break;
			}
		}

		if (u == -1) {
			print(0);
			continue;
		}

		vector<bool> v(n, false);
		v[u] = true;
		u = adj[u][0];
		bool flag = true;
		while (adj[u].size() > 1) {
			if (adj[u].size() > 2) {
				flag = false;
				break;
			}
			if (v[adj[u][0]] and v[adj[u][1]]) {
				flag = false;
				break;
			}
			v[u] = true;
			u = v[adj[u][0]] ? adj[u][1] : adj[u][0];
		}
		v[u] = true;

		rep(i, 0, n) {
			if (graph[i].size() > 1 and !v[i]) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			print(0);
			continue;
		}

		vector<int> l(n, 0);
		rep(i, 0, n) {
			if (graph[i].size() == 1) {
				l[graph[i][0]]++;
			}
		}

		int res = 1;
		rep(i, 0, n) {
			res = res * fact[l[i]] % MOD;
		}
		print(res * 4 % MOD);
	}
}
