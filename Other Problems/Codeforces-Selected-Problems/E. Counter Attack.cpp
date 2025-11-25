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

void dfs(int u, vector<vector<bool>> &graph, vector<bool> &vis, vector<int> &a, vector<int> &l) {
	vis[u] = true;
	a.push_back(l[u] + 1);
	rep(v, 0, graph.size()) {
		if (!vis[v] and graph[u][v]) {
			dfs(v, graph, vis, a, l);
		}
	}
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<pair<int, int>> e;
	vector<int> d(n);
	rep(i, 0, m) {
		int u, v;
		input(u, v);

		u--;
		v--;
		e.push_back({u, v});
		d[u]++;
		d[v]++;
	}

	vector<vector<int>> res;
	vector<int> l, s(n, -1);
	int k = 1000, c = 0, o = n;
	if (n > 2000) {
		res.push_back({});
		rep(i, 0, n) {
			if (d[i] <= k) {
				res.back().push_back(i + 1);
			}
			else {
				s[i] = c;
				l.push_back(i);
				c++;
			}
		}
		n = c;
	}
	else {
		l.resize(n);
		rep(i, 0, n) {
			s[i] = i;
			l[i] = i;
		}
	}

	vector<int> p(n, 0);
	vector<vector<bool>> graph(n, vector<bool>(n, true));
	for (auto [u, v] : e) {
		if (s[u] != -1 and s[v] != -1) {
			graph[s[u]][s[v]] = false;
			graph[s[v]][s[u]] = false;
		}
		else if (s[u] == -1 and s[v] != -1) {
			p[s[v]]++;
		}
		else if (s[u] != -1 and s[v] == -1) {
			p[s[u]]++;
		}
	}

	vector<bool> vis(n, false);
	rep(i, 0, n) {
		if (!vis[i] and p[i] != o - n) {
			dfs(i, graph, vis, res.back(), l);
		}
	}

	rep(i, 0, n) {
		if (!vis[i]) {
			res.push_back({});
			dfs(i, graph, vis, res.back(), l);
		}
	}
	print(res.size());
	for (vector<int> v : res) {
		cout << v.size() << ' ';
		arrprint(v);
	}
}
