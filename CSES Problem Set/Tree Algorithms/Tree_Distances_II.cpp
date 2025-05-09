#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void dfs1(int u, int p, vector<vector<int>> &graph, vector<int> &s, vector<int> &dp) {
	for (int v : graph[u]) {
		if (v != p) {
			dfs1(v, u, graph, s, dp);
			s[u] += s[v];
			dp[u] += dp[v] + s[v];
		}
	}
}

void dfs2(int u, int p, vector<vector<int>> &graph, vector<int> &s, vector<int> &dp) {
	for (int v : graph[u]) {
		if (v != p) {
			dp[v] = dp[u] + graph.size() - 2 * s[v];
			dfs2(v, u, graph, s, dp);
		}
	}
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> s(n, 1), dp(n, 0);
	dfs1(0, -1, graph, s, dp);
	dfs2(0, -1, graph, s, dp);
	arrprint(dp);
}
