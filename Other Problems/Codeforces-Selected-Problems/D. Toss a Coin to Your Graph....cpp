#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

bool dfs(int u, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &a, int x, vector<int> &topo, vector<bool> &in_stack) {
	vis[u] = true;
	in_stack[u] = true;
	for (int v : graph[u]) {
		if (a[v] > x) {
			continue;
		}

		if (in_stack[v] or (!vis[v] and dfs(v, graph, vis, a, x, topo, in_stack))) {
			return true;
		}
	}
	topo.push_back(u);
	in_stack[u] = false;
	return false;
}

bool check(int x, vector<vector<int>> &graph, vector<int> &a, int k) {
	int n = graph.size();
	vector<bool> vis(n, false), in_stack(n, false);
	vector<int> topo;
	range(i, 0, n) {
		if (a[i] <= x and !vis[i]) {
			if (dfs(i, graph, vis, a, x, topo, in_stack)) {
				return true;
			}
		}
	}

	vector<int> dp(n, 0);
	for (int u : topo) {
		for (int v : graph[u]) {
			if (a[v] <= x) {
				dp[u] = max(dp[u], dp[v]);
			}
		}
		dp[u]++;
	}
	
	return *max_element(dp.begin(), dp.end()) >= k;
}

int32_t main() {
	setup();

	int n, m, k;
	input(n, m, k);

	vector<int> a(n);
	arrPut(a);

	vector<vector<int>> graph(n);
	range(i, 0, m) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
	}

	int l = 0, r = 1e9, res = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (check(m, graph, a, k)) {
			res = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	print(res);
}
