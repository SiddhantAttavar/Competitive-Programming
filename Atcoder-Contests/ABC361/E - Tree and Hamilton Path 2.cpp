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

void dfs(int u, int p, vector<vector<pair<int, int>>> &graph, vector<int> &d) {
	for (pair<int, int> v : graph[u]) {
		if (v.first != p) {
			d[v.first] = d[u] + v.second;
			dfs(v.first, u, graph, d);
		}
	}
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<pair<int, int>>> graph(n);
	int res = 0;
	range(i, 0, n - 1) {
		int a, b, c;
		input(a, b, c);

		graph[a - 1].push_back({b - 1, c});
		graph[b - 1].push_back({a - 1, c});
		res += c;
	}
	res *= 2;

	vector<int> d(n);
	d[0] = 0;
	dfs(0, -1, graph, d);

	int u = max_element(d.begin(), d.end()) - d.begin();
	d = vector<int>(n, 0);
	d[u] = 0;
	dfs(u, -1, graph, d);

	print(res - *max_element(d.begin(), d.end()));
}
