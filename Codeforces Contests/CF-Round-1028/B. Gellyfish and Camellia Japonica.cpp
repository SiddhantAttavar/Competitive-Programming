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

bool check(vector<int> a, vector<tuple<int, int, int>> &v, vector<int> &b) {
	for (auto [x, y, z] : v) {
		a[z] = min(a[x], a[y]);
	}
	return a == b;
}

void dfs(int u, vector<vector<int>> &graph, vector<int> &t, vector<bool> &vis) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, t, vis);
		}
	}
	t.push_back(u);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vector<int> b(n);
		arrput(b);

		vector<int> u(n);
		rep(i, 0, n) {
			u[i] = i;
		}

		vector<tuple<int, int, int>> v(q);
		vector<vector<int>> graph(n);
		rep(i, 0, q) {
			int x, y, z;
			input(x, y, z);
			x--;
			y--;
			z--;
			v[i] = {x, y, z};
			int w = graph.size();
			graph.push_back({});
			graph[w].push_back(u[x]);
			graph[w].push_back(u[y]);
			u[z] = w;
		}

		vector<int> t;
		vector<bool> vis(graph.size(), false);
		rep(i, 0, n) {
			if (!vis[u[i]]) {
				dfs(u[i], graph, t, vis);
			}
		}
		reverse(t.begin(), t.end());

		vector<int> l(graph.size(), 1);
		rep(i, 0, n) {
			l[u[i]] = b[i];
		}
		for (int u : t) {
			for (int v : graph[u]) {
				l[v] = max(l[v], l[u]);
			}
		}

		vector<int> a(n);
		rep(i, 0, n) {
			a[i] = l[i];
		}

		if (check(a, v, b)) {
			arrprint(a);
		}
		else {
			print(-1);
		}
	}
}
