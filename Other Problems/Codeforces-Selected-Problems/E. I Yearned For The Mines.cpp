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

void erase(int u, vector<set<int>> &graph, vector<pair<int, bool>> &res) {
	for (int v : graph[u]) {
		graph[v].erase(u);
	}
	graph[u].clear();
	res.push_back({u, true});
	res.push_back({u, false});
}

bool dfs(int u, int p, vector<set<int>> &graph, vector<pair<int, bool>> &res) {
	bool flag = true;
	vector<int> l(graph[u].begin(), graph[u].end());
	for (int v : l) {
		if (v != p) {
			flag &= dfs(v, u, graph, res);
		}
	}
	if (graph[u].size() + (p == -1) >= 4 or !flag) {
		erase(u, graph, res);
		return true;
	}
	if (graph[u].size() <= 2) {
		return true;
	}
	return false;
}

void dfs(int u, vector<set<int>> &graph, vector<int> &l, vector<bool> &vis) {
	l.push_back(u);
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, l, vis);
		}
	}
}
 
int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<set<int>> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].insert(v - 1);
			graph[v - 1].insert(u - 1);
		}

		vector<pair<int, bool>> res;
		dfs(0, -1, graph, res);

		vector<bool> vis(n, false);
		for (auto [i, o] : res) {
			vis[i] = true;
		}
		rep(i, 0, n) {
			if (vis[i] or graph[i].size() > 1) {
				continue;
			}

			vector<int> l;
			dfs(i, graph, l, vis);
			for (int j : l) {
				res.push_back({j, false});
			}
		}

		// assert(res.size() <= (5 * n) / 4);
		print(res.size());
		for (auto [i, o] : res) {
			print(o + 1, i + 1);
		}
	}
}
