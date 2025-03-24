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

int dfs(int u, int p, vector<vector<int>> &graph, vector<vector<int>> &dp) {
	int res = 0, k = dp[0].size() - 1;
	dp[u][0] = 1;
	for (int v : graph[u]) {
		if (v != p) {
			res += dfs(v, u, graph, dp);
			rep(i, 0, k) {
				res += dp[v][i] * dp[u][k - i - 1];
			}
			rep(i, 0, k) {
				dp[u][i + 1] += dp[v][i];
			}
		}
	}
	return res;
}

int32_t main() {
	setup();
	int n, k;
	input(n, k);

	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<vector<int>> dp(n, vector<int>(k + 1, 0));
	print(dfs(0, -1, graph, dp));
}
