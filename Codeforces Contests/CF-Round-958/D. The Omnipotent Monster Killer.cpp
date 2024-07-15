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

void dfs(int u, int p, vector<vector<int>> &tree, vector<vector<int>> &f, vector<vector<int>> &g, vector<vector<int>> &h, int k, vector<int> &a) {
	for (int v : tree[u]) {
		if (v != p) {
			dfs(v, u, tree, f, g, h, k, a);
			f[u][0] += h[v][1];
			range(i, 1, k - 1) {
				f[u][i] += min(g[v][i - 1], h[v][i + 1]);
			}
			f[u][k - 1] += g[v][k - 2];
		}
	}
	range(i, 0ll, k) {
		f[u][i] += a[u] * (i + 1);
	}
	g[u][0] = f[u][0];
	range(i, 1, k) {
		g[u][i] = min(g[u][i - 1], f[u][i]);
	}
	h[u][k - 1] = f[u][k - 1];
	for (int i = k - 2; i >= 0; i--) {
		h[u][i] = min(h[u][i + 1], f[u][i]);
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		vector<vector<int>> tree(n);
		range(i, 0, n - 1) {
			int u, v;
			input(u, v);
			
			tree[u - 1].push_back(v - 1);
			tree[v - 1].push_back(u - 1);
		}

		int k = 30;
		vector<vector<int>> f(n, vector<int>(k, 0)), g(n, vector<int>(k)), h(n, vector<int>(k));
		dfs(0, -1, tree, f, g, h, k, a);
		print(g[0][k - 1]);
	}
}
