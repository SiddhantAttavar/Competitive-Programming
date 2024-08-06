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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int dfs(int u, vector<vector<int>> &graph, vector<int> &d, vector<int> &a) {
	int x = 1e9;
	for (int v : graph[u]) {
		x = min(x, dfs(v, graph, d, a));
	}

	if (x < a[u]) {
		return d[u] = x;
	}

	if (x == 1e9) {
		return d[u] = a[u];
	}

	return d[u] = (x + a[u]) / 2;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n), p(n - 1);
		arrPut(a);
		arrPut(p);

		vector<vector<int>> graph(n);
		range(i, 0, n - 1) {
			graph[p[i] - 1].push_back(i + 1);
		}

		vector<int> d(n, 0);
		dfs(0, graph, d, a);

		int x = 1e9;
		for (int i : graph[0]) {
			x = min(x, d[i]);
		}
		print(a[0] + x);
	}
}
