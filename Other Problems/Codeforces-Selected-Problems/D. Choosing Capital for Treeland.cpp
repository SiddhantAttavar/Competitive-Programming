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

int dfs1(int u, int p, vector<vector<pair<int, int>>> &graph) {
	int res = 0;
	for (auto [v, w] : graph[u]) {
		if (v != p) {
			res += dfs1(v, u, graph) + w;
		}
	}
	return res;
}

void dfs2(int u, int p, vector<vector<pair<int, int>>> &graph, vector<int> &res) {
	for (auto [v, w] : graph[u]) {
		if (v != p) {
			res[v] = res[u] + 1 - 2 * w;
			dfs2(v, u, graph, res);
		}
	}
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<pair<int, int>>> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back({v - 1, 0});
		graph[v - 1].push_back({u - 1, 1});
	}

	vector<int> res(n, 0);
	res[0] = dfs1(0, -1, graph);
	dfs2(0, -1, graph, res);

	int k = *min_element(res.begin(), res.end());
	print(k);
	rep(i, 0, n) {
		if (res[i] == k) {
			cout << i + 1 << ' ';
		}
	}
	cout << endl;
}
