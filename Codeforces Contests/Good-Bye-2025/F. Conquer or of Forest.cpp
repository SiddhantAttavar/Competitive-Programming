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

void dfs1(int u, int p, vector<vector<int>> &graph, vector<int> &s) {
	for (int v : graph[u]) {
		if (v != p) {
			dfs1(v, u, graph, s);
			s[u] += s[v];
		}
	}
}

void dfs2(int u, int p, vector<vector<int>> &graph, vector<int> &s, vector<int> &t) {
	for (int v : graph[u]) {
		if (v != p) {
			dfs2(v, u, graph, s, t);
			if (s[v] % 2) {
				t[u] += t[v];
			}
		}
	}
}

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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<int> s(n, 1), t(n, 1);
		dfs1(0, -1, graph, s);
		dfs2(0, -1, graph, s, t);

		vector<int> l = {t[0]};
		rep(i, 1, n) {
			if (s[i] % 2 == 0) {
				l.push_back(t[i]);
			}
		}

		if (l.size() == 1) {
			print(1);
			continue;
		}

		int res = 1;
		rep(i, 1, ((int) l.size() - 1)) {
			res = res * i % MOD;
		}
		for (int i : l) {
			res = res * i % MOD * i % MOD;
		}
		res = mdiv(res, l[0]);

		int c = (MOD - mdiv(1, l[0])) % MOD;
		for (int i : l) {
			c = (c + mdiv(1, i)) % MOD;
		}
		print(res * c % MOD);
	}
}
