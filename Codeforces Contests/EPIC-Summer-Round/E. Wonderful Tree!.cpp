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

int dfs(int u, vector<vector<int>> &graph, vector<int> &a, vector<int> &b, vector<vector<int>> &l) {
	int res = 0;
	if (graph[u].size() == 0) {
		b[u] = 1e12;
	}

	for (int v : graph[u]) {
		res += dfs(v, graph, a, b, l);
		range(i, 0, l[v].size() - 1) {
			l[u][i + 1] += l[v][i];
		}
		b[u] += a[v];
	}

	if (a[u] <= b[u]) {
		l[u][0] = b[u] - a[u];
		return res;
	}

	int x = a[u] - b[u];
	range(i, 0, l[u].size()) {
		int t = min(x, l[u][i]);
		res += t * i;
		x -= t;
		l[u][i] -= t;
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n), p(n - 1), b(n, 0);
		arrPut(a);
		arrPut(p);

		vector<vector<int>> graph(n);
		range(i, 0, n - 1) {
			graph[p[i] - 1].push_back(i + 1);
		}
		
		vector<vector<int>> l(n, vector<int>(n, 0));
		print(dfs(0, graph, a, b, l));
	}
}
