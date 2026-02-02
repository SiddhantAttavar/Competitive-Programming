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

int dfs(int u, int p, int k, vector<vi> &graph, vector<map<int, int>> &m, vi &d) {
	int res = 0;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		d[v] = d[u] + 1;
		res += dfs(v, u, k, graph, m, d);

		if (sz(m[v]) > sz(m[u])) {
			swap(m[v], m[u]);
		}
		for (auto [x, v] : m[v]) {
			res += v * m[u][k + 2 * d[u] - x];
		}
		for (auto [x, v] : m[v]) {
			m[u][x] += v;
		}
	}
	res += m[u][k + d[u]];
	m[u][d[u]]++;
	return res;
}

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	vector<vi> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<map<int, int>> m(n);
	vi d(n);
	print(dfs(0, -1, k, graph, m, d));
}
