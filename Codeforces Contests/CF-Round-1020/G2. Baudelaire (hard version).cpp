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
const int MOD = (int) 1e9 + 7; //998244353;

int query1(vector<int> v) {
	if (v.empty()) {
		return 0;
	}
	cout << "? 1 " << v.size() << ' ';
	for (int i : v) {
		cout << i + 1 << ' ';
	}
	cout << '\n';
	cout.flush();
	int x;
	input(x);
	return x;
}

void query2(int i) {
	print("? 2", i + 1);
	cout.flush();
}

#define vi vector<int>

vector<vi> decomp;
vector<vi> adj;
vi siz;
vector<bool> vis;
void find_size(int v, int p) {
	siz[v] = 1;
	for(auto nx : adj[v]) if(nx != p && !vis[nx]) {
		find_size(nx, v);
		siz[v] += siz[nx];
	}
}
int centroid(int v, int p, int n) {
	for(auto nx : adj[v]) if(nx != p && !vis[nx] && siz[nx] > n
			/2) {
		return centroid(nx, v, n);
	}
	return v;
}
void process(int v) {}
int solve(int v, int p) {
	find_size(v, p);
	int c = centroid(v, p, siz[v]);
	process(c);
	vis[c] = true;
	for(auto nx : adj[c]) if(!vis[nx]) decomp[c].push_back(solve(nx, c));
	return c;
}

void dfs(int u, vector<vector<int>> &graph, vector<int> &l) {
	l.push_back(u);
	for (int v : graph[u]) {
		dfs(v, graph, l);
	}
}

void solve(int u, int p, int x, vector<vector<int>> &graph, vector<int> &res) {
	res[u] = query1({u}) - x;
	x += res[u];
	for (int v : graph[u]) {
		if (v != p) {
			solve(v, u, x, graph, res);
		}
	}
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		adj.clear();
		decomp.clear();
		siz.clear();
		vis.clear();

		adj = vector<vector<int>>(graph.begin(), graph.end());
		decomp.resize(n);
		siz.resize(n, 0);
		vis.resize(n, false);

		int u = solve(0, 0);
		int s = -1;
		while (true) {
			vector<int> v;
			dfs(u, decomp, v);
			int x = query1(v);
			if (!v.empty()) {
				query2(u);
			}
			int y = query1(v);
			if (abs(x - y) == 2 * v.size()) {
				s = u;
				break;
			}

			int l = 0, r = decomp[u].size() - 1;
			int w = u;
			while (l <= r) {
				int m = (l + r) / 2;
				vector<int> v;
				rep(i, m + 1, decomp[u].size()) {
					dfs(decomp[u][i], decomp, v);
				}
				int x = query1(v);
				if (!v.empty()) {
					query2(u);
				}
				int y = query1(v);
				if (abs(x - y) == 2 * v.size()) {
					w = decomp[u][m];
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}
			u = w;
		}

		vector<int> res(n);
		solve(s, -1, 0, graph, res);
		cout << "! ";
		arrprint(res);
		cout.flush();
	}
}
