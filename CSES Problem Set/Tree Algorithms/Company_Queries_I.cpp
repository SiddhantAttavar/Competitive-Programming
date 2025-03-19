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

void dfs(int u, int p, vector<vector<int>> &graph, vector<vector<int>> &par) {
	for (int v : graph[u]) {
		par[v][0] = u;
		rep(i, 1, 20) {
			if (par[v][i - 1] == -1) {
				break;
			}
			par[v][i] = par[par[v][i - 1]][i - 1];
		}
		dfs(v, u, graph, par);
	}
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		int p;
		input(p);
		graph[p - 1].push_back(i + 1);
	}

	vector<vector<int>> par(n, vector<int>(20, -1));
	dfs(0, -1, graph, par);

	while (q--)  {
		int u, k;
		input(u, k);
		u--;
		for (int i = 19; i >= 0; i--) {
			if ((1 << i) & k) {
				u = par[u][i];
			}
			if (u == -1) {
				u = -2;
				break;
			}
		}
		print(u + 1);
	}
}
