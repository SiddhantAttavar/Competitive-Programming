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

void dfs(int u, vector<vector<int>> &graph, vector<int> &s) {
	for (int v : graph[u]) {
		dfs(v, graph, s);
		s[u] += s[v];
	}
}

int dfs1(int u, vector<vector<int>> &graph, vector<int> &s) {
	int m = -1;
	for (int v : graph[u]) {
		if (m == -1 or s[m] < s[v]) {
			m = v;
		}
	}
	if (m == -1) {
		return 1;
	}
	if (2 * s[m] <= s[u] - 1) {
		return (s[u] - 1) % 2 + 1;
	}
	int x = dfs1(m, graph, s);
	if (x <= s[u] - s[m] - 1) {
		return (s[u] - 1) % 2 + 1;
	}
	return x - (s[u] - s[m] - 1) + 1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> graph(n);
		rep(i, 0, n - 1) {
			int p;
			input(p);
			graph[p - 1].push_back(i + 1);
		}

		vector<int> s(n, 1);
		dfs(0, graph, s);

		print((n - dfs1(0, graph, s)) / 2);
	}
}
