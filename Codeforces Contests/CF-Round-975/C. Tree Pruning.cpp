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
const int MOD = (int) 1e9 + 7; //998244353

void dfs(int u, int p, vector<vector<int>> &graph, vector<int> &l, vector<int> &f) {
	f[u] = l[u];
	for (int v : graph[u]) {
		if (v != p) {
			l[v] = l[u] + 1;
			dfs(v, u, graph, l, f);
			f[u] = max(f[u], f[v]);
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> graph(n);
		range(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<int> l(n, 0), f(n, 0);
		dfs(0, -1, graph, l, f);

		vector<int> a(n, 0), b(n, 0);
		a[0] = 1;
		range(i, 0, n) {
			a[l[i]]++;
			b[f[i]]++;
		}

		int res = n;
		int x = 0, y = n;
		for (int i = n - 1; i >= 0; i--) {
			y -= b[i];
			res = min(res, x + y);
			x += a[i];
		}
		print(res);
	}
}
