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

bool dfs(int u, int p, int k, vector<vector<int>> &graph, vector<int> &dp) {
	vector<int> a;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		if (!dfs(v, u, k, graph, dp)) {
			return false;
		}

		if (dp[v]) {
			a.push_back(dp[v]);
		}
	}

	if (a.size() == 0) {
		dp[u] = 1;
		return true;
	}

	if (a.size() > 2) {
		return false;
	}

	if (a.size() == 1) {
		dp[u] = (a[0] + 1) % k;
		return true;
	}

	if (a[0] + a[1] + 1 != k) {
		return false;
	}

	dp[u] = 0;
	return true;
}

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	if (k == 1) {
		print("Yes");
		return 0;
	}

	vector<vector<int>> graph(n * k);
	rep(i, 0, n * k - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> dp(n * k, 0);
	if (dfs(0, -1, k, graph, dp) and dp[0] == 0) {
		print("Yes");
	}
	else {
		print("No");
	}
}
