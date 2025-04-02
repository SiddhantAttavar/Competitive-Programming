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

void dfs(int u, vector<vector<int>> &graph, vector<int> &d) {
	for (int v : graph[u]) {
		if (d[v] == -1) {
			d[v] = d[u] + 1;
			dfs(v, graph, d);
		}
	}
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> d(n, -1);
	d[0] = 0;
	dfs(0, graph, d);
	int k = max_element(d.begin(), d.end()) - d.begin();
	d = vector<int>(n, -1);
	d[k] = 0;
	dfs(k, graph, d);
	int res = 0;
	k = *max_element(d.begin(), d.end());
	while ((1 << res) < k) {
		res++;
	}
	print(res);
}
