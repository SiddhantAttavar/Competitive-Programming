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

int dfs(int u, int p, vector<vector<int>> &graph, int &res, int x) {
	int s = 1;
	for (int v : graph[u]) {
		if (v != p) {
			s += dfs(v, u, graph, res, x);
		}
	}
	if (s >= x) {
		res++;
		return 0;
	}
	return s;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<vector<int>> graph(n);
		range(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		int l = 0, r = n, res = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			int c = 0;
			dfs(0, -1, graph, c, m);
			if (c > k) {
				l = m + 1;
				res = m;
			}
			else {
				r = m - 1;
			}
		}
		print(res);
	}
}
