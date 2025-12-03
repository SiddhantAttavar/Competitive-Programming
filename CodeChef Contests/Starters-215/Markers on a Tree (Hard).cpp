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

int mpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
	}
	return res;
}

int dfs(int u, int p1, int p2, vector<vector<int>> &graph, vector<int> &s) {
	int res = 0;
	for (int v : graph[u]) {
		if (v != p1 and v != p2) {
			res = (res + dfs(v, u, -1, graph, s) + mpow(2, s[v])) % MOD;
			s[u] += s[v];
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> p(n, -1);
		vector<vector<int>> graph(n);
		rep(i, 1, n) {
			input(p[i]);
			p[i]--;
			graph[i].push_back(p[i]);
			graph[p[i]].push_back(i);
		}

		vector<int> v;
		int u = n - 1;
		while (u) {
			v.push_back(u);
			u = p[u];
		}
		v.push_back(0);

		int k = v.size();
		vector<int> l(k);
		vector<int> s(n, 1);
		l[0] = dfs(v[0], v[1], -1, graph, s);
		rep(i, 1, k - 1) {
			l[i] = dfs(v[i], v[i - 1], v[i + 1], graph, s);
		}
		l[k - 1] = dfs(v[k - 1], v[k - 2], -1, graph, s);

		vector<int> dp(k);
		dp[0] = l[0];
		rep(i, 0, k) {
			vector<int> ndp = dp;
			rep(j, 0, k - 1) {
				ndp[j + 1] = (ndp[j + 1] + dp[j]) % MOD;
			}
			rep(j, 0, k) {
				ndp[j] = (ndp[j] + dp[j] * (l[i] + mpow(2, s[v[i]]))) % MOD;
			}
			dp = ndp;
		}

		int res = 0;
		rep(i, 0, k) {
			res = (res + dp[i]) % MOD;
		}
		print(res);
	}
}
