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
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

#define IS_BRIDGE(x, y) {graph[x].push_back(y); graph[y].push_back(x);};
#define IS_CUTPOINT(x)

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> tin, low;
vector<vi> graph;
int timer;
void dfs(int v, int p = -1) {
	visited[v] = true;
	tin[v] = low[v] = timer++;
	int children=0;
	for (int to : adj[v]) {
		if (to == p) continue;
		if (visited[to]) {
			low[v] = min(low[v], tin[to]);
		} else {
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if (low[to] > tin[v]) // CUT EDGE
				IS_BRIDGE(v, to)
			if (low[to] >= tin[v] and p != -1)
				IS_CUTPOINT(v);
			++children;
		}
	}
	if(p == -1 && children > 1)
		IS_CUTPOINT(v);
}
void find_cutpoints_and_bridges() {
	timer = 0;
	visited.assign(n, false);
	tin.assign(n, -1);
	low.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		if (!visited[i])
			dfs (i);
	}
}

int dfs1(int u, vector<vi> &graph, vi &vis) {
	vis[u] = true;
	int res = sz(graph[u]);
	for (int v : graph[u]) {
		if (!vis[v]) {
			res += dfs1(v, graph, vis);
		}
	}
	return res;
}


int32_t main() {
	setup();
	int m;
	input(n, m);

	adj.resize(n);
	graph.resize(n);
	rep(i, 0, m) {
		int u, v;
		input(u, v);
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}

	find_cutpoints_and_bridges();

	vi vis(n, false);
	int res = 0;
	rep(i, 0, n) {
		if (!vis[i]) {
			int x = dfs1(i, graph, vis);
			res += (x / 2 + 1) / 2;
		}
	}
	print(res);
}
