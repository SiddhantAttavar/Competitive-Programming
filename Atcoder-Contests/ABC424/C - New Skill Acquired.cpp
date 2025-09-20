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

void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis);
		}
	}
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<int>> graph(n);
	vector<bool> v(n, false);
	rep(i, 0, n) {
		int a, b;
		input(a, b);

		if (a == 0) {
			v[i] = true;
			continue;
		}

		graph[a - 1].push_back(i);
		graph[b - 1].push_back(i);
	}

	vector<bool> vis(n, false);
	rep(i, 0, n) {
		if (!vis[i] and v[i]) {
			dfs(i, graph, vis);
		}
	}

	print(accumulate(vis.begin(), vis.end(), 0ll));
}
