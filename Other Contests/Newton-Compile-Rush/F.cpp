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

void dfs(int u, vector<vector<int>> &graph, vector<vector<int>> &par, vector<vector<int>> &gcd, vector<int> &a) {
	for (int v : graph[u]) {
		if (v == par[u][0]) {
			continue;
		}

		par[v][0] = u;
		gcd[v][0] = a[v];
		range(i, 1, par[v].size()) {
			if (par[v][i - 1] == -1) {
				break;
			}

			par[v][i] = par[par[v][i - 1]][i - 1];
			gcd[v][i] = __gcd(gcd[v][i - 1], gcd[par[v][i - 1]][i - 1]);
		}
		dfs(v, graph, par, gcd, a);
	}
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<int> a(n);
	arrPut(a);

	vector<vector<int>> graph(n);
	range(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	int h = 0;
	while ((1 << h) < n) {
		h++;
	}
	h++;

	vector<vector<int>> par(n, vector<int>(h, -1)), gcd(n, vector<int>(h, 0));
	gcd[0][0] = a[0];
	dfs(0, graph, par, gcd, a);

	while (q--) {
		int k;
		input(k);
	}
}
