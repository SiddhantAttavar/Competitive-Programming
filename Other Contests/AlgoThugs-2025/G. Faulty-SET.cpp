#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = 998244353;

void dfs(int u, int p, vector<vector<int>> &graph, vector<bitset<26>> &pref, string &s) {
	for (int v : graph[u]) {
		if (v != p) {
			pref[v] = pref[u];
			pref[v][s[v] - 'a'].flip();
			dfs(v, u, graph, pref, s);
		}
	}
}

int solve(int b, string &s) {
	int f = 1, g = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		int x = (g * __builtin_popcount(b & ((1 << (s[i] - 'a')) - 1))) % MOD;
		if (b & (1 << (s[i] - 'a'))) {
			x = (x + f) % MOD;
		}
		int y = (g * __builtin_popcount(b)) % MOD;
		f = x;
		g = y;
	}
	return f;
}

int32_t main() {
	setup();
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

	vector<bitset<26>> pref(n, 0);
	pref[0][s[0] - 'a'] = 1;
	dfs(0, -1, graph, pref, s);

	int q;
	input(q);
	while (q--) {
		string s, t;
		input(s, t);

		int x, y;
		input(x, y);

		bitset<26> b = pref[x - 1] ^ pref[y - 1];
		bool flag = true;
		for (char c : t) {
			if (!b[c - 'a']) {
				flag = false;
				break;
			}
		}

		print((solve(b.to_ullong(), t) - solve(b.to_ullong(), s) - flag + 2 * MOD) % MOD);
	}
}
