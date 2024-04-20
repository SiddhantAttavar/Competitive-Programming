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

void dfs(int u, int p, vector<vector<pair<int, int>>> &graph, vector<int> &a) {
	for (pair<int, int> e : graph[u]) {
		if (e.first != p) {
			a[e.first] = a[u] ^ e.second;
			dfs(e.first, u, graph, a);
		}
	}
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<pair<int, int>>> graph(n);
	range(i, 0, n - 1) {
		int u, v, w;
		input(u, v, w);

		graph[u - 1].push_back({v - 1, w});
		graph[v - 1].push_back({u - 1, w});
	}

	vector<int> a(n, 0);
	dfs(0, -1, graph, a);

	int res = 0;
	int m = 0;
	for (int i = 30; i >= 0; i--) {
		set<int> s;
		m |= 1 << i;
		for (int j : a) {
			s.insert(j & m);
		}

		int c = res | (1 << i);

		for (int x : s) {
			if (s.count(c ^ x)) {
				res = c;
				break;
			}
		}
	}

	print(res);
}
