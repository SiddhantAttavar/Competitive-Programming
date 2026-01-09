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

bool bridges = false;
#define IS_BRIDGE(x, y) bridges = true
#define IS_CUTPOINT(v)
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> tin, low;
int timer;
void dfs(int v, int p = -1) {
	visited[v] = true;
	tin[v] = low[v] = timer++;
	int children=0; // CUT VERTICE
		for (int to : adj[v]) {
			if (to == p) continue;
			if (visited[to]) {
				low[v] = min(low[v], tin[to]);
			} else {
				dfs(to, v);
				low[v] = min(low[v], low[to]);
				if (low[to] > tin[v]) {// CUT EDGE
					IS_BRIDGE(v, to);
				}
			}
		}
	if(p == -1 && children > 1) // CUT VERTICE
		IS_CUTPOINT(v);
}
void find_cutpoints() { // CUT VERTICE
	timer = 0;
	visited.assign(n, false);
	tin.assign(n, -1);
	low.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		if (!visited[i])
			dfs (i);
	}
}
void find_bridges() { // CUT EDGE
	timer = 0;
	visited.assign(n, false);
	tin.assign(n, -1);
	low.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		if (!visited[i])
			dfs(i);
	}
}

void dfs(int u, int p, vector<vector<int>> &graph, vector<pair<int, int>> &res, vector<bool> &vis, set<pair<int, int>> &s) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!s.count({u, v}) and !s.count({v, u})) {
			res.push_back({v, u});
			s.insert({u, v});
		}
		if (!vis[v]) {
			dfs(v, u, graph, res, vis, s);
		}
	}
}

int32_t main() {
	setup();

	int m;
	input(n, m);

	vector<vector<int>> graph(n);
	rep(i, 0, m) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	adj = graph;
	find_bridges();

	if (bridges) {
		print("IMPOSSIBLE");
		return 0;
	}

	vector<pair<int, int>> res;
	vector<bool> vis(n, false);
	set<pair<int, int>> s;
	dfs(0, -1, graph, res, vis, s);

	rep(i, 1, n) {
		if (!vis[i]) {
			print("IMPOSSIBLE");
			return 0;
		}
	}

	for (auto [u, v] : res) {
		print(u + 1, v + 1);
	}
}
