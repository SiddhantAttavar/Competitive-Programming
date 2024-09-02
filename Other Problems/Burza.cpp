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

void dfs(int u, int p, vector<vector<int>> &graph, vector<bool> &a, vector<int> &l, int k) {
	a[u] = l[u] >= k;
	for (int v : graph[u]) {
		if (v != p) {
			l[v] = l[u] + 1;
			dfs(v, u, graph, a, l, k);
			a[u] = a[u] or a[v];
		}
	}
}

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	vector<vector<int>> graph(n);
	range(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<bool> a(n, false);
	vector<int> l(n, 0);
	dfs(0, -1, graph, a, l, k);

	vector<vector<int>> b(n);
	range(i, 0, n) {
		for (int j : graph[i]) {
			if (l[j] == l[i] + 1 and a[j]) {
				b[i].push_back(j);
			}
		}
	}

	int u = 0;
	range(i, 0, k - 1) {
		if (b[u].size() == 1) {
			print("DA");
			return 0;
		}

		if (b[u].size() > 2) {
			print("NE");
			return 0;
		}

		if (b[b[u][0]].size() <= 1) {
			u = b[u][0];
		}
		else if (b[b[u][1]].size() <= 1) {
			u = b[u][1];
		}
		else {
			print("NE");
			return 0;
		}
	}

	if (b[u].size() == 1) {
		print("DA");
	}
	else {
		print("NE");
	}
}
