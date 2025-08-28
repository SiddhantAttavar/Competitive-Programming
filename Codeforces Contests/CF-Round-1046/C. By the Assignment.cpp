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

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> tin, low;
int timer;
set<pair<int, int>> bridges;
void dfs(int v, int p = -1) {
	visited[v] = true;
	tin[v] = low[v] = timer++;
	for (int to : adj[v]) {
		if (to == p) continue;
		if (visited[to]) {
			low[v] = min(low[v], tin[to]);
		} else {
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if (low[to] > tin[v])  // CUT EDGE
				bridges.insert({v, to});
		}
	}
}
void find_bridges(vector<vector<int>> graph) { // CUT EDGE
	adj = graph;
	n = adj.size();
	timer = 0;
	visited.assign(n, false);
	tin.assign(n, -1);
	low.assign(n, -1);
	bridges.clear();
	for (int i = 0; i < n; ++i) {
		if (!visited[i])
			dfs(i);
	}
}

bool dfs2(int u, vector<vector<int>> &graph, vector<int> &c) {
	bool res = true;
	for (int v : graph[u]) {
		if (c[v] == -1) {
			c[v] = 1 - c[u];
			if (!dfs2(v, graph, c)) {
				res = false;
			}
		}
		else if (c[v] == c[u]) {
			res = false;
		}
	}
	return res;
}

int dfs3(int u, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &a) {
	vis[u] = true;
	int res = a[u];
	for (int v : graph[u]) {
		if (vis[v]) {
			continue;
		}

		int x = dfs3(v, graph, vis, a);
		if (x != -1 and res != -1 and x != res) {
			res = -2;
		}
		else if (res == -1) {
			res = x;
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, v;
		input(n, m, v);
		v %= MOD;

		vector<int> a(n);
		arrput(a);

		vector<vector<int>> graph(n);
		rep(i, 0, m) {
			int u, v;
			input(u, v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		find_bridges(graph);
		vector<vector<int>> temp(n);
		rep(u, 0, n) {
			for (int v : graph[u]) {
				if (!bridges.count({u, v}) and !bridges.count({v, u})) {
					temp[u].push_back(v);
				}
			}
		}
		graph = temp;

		vector<int> c(n, -1);
		vector<bool> vis(n, false);
		int res = 1;
		rep(i, 0, n) {
			if (c[i] != -1) {
				continue;
			}

			c[i] = 0;
			int x = dfs3(i, graph, vis, a);
			if (dfs2(i, graph, c)) {
				if (x == -1) {
					res = res * v % MOD;
				}
				else if (x == -2) {
					res = 0;
					break;
				}
			}
			else {
				if (x != -1 and x != 0) {
					res = 0;
					break;
				}
			}
		}
		print(res);
	}
}
