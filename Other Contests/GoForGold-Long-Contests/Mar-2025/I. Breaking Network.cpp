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

int dfs(int u, int p, int k, vector<vector<int>> &graph, vector<vector<int>> &dp, vector<vector<int>> &pdp , vector<int> &a) {
	int res = a[u] == ((1 << k) - 1);
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}
		res += dfs(v, u, k, graph, dp, pdp, a);
	}
	vector<int> f(1 << k, 0);
	f[0] = 1;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}
		rep(i, 0, 1 << k) {
			res += dp[v][i] * f[((1 << k) - 1) ^ (i | a[u])];
		}
		rep(i, 0, 1 << k) {
			f[i] += pdp[v][i];
		}
	}
	dp[u][a[u]] = 1;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		rep(i, 0, 1 << k) {
			dp[u][i | a[u]] += dp[v][i];
		}
	}
	pdp[u] = vector<int>(dp[u].begin(), dp[u].end());
	rep(j, 0, k) {
		rep(i, 0, 1 << k) {
			if (((1 << j) & i) == 0) {
				pdp[u][i] += pdp[u][i | (1 << j)];
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

	vector<int> a(n);
	rep(i, 0, n) {
		rep(j, 0, k) {
			int x;
			input(x);
			a[i] = a[i] << 1 | x;
		}
	}

	vector<vector<int>> dp(n, vector<int>(1 << k, 0)), pdp(n, vector<int>(1 << k, 0));
	print(dfs(0, -1, k, graph, dp, pdp, a));
}
