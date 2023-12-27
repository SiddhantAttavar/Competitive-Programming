#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int dfs(int u, int p, int d, vector<vector<int>> &graph, vector<int> &l, vector<int> &m) {
	int res = 0;
	bool flag = true;

	l[u] = 0;
	for (int v : graph[u]) {
		if (v != p) {
			flag = false;
			res = max(res, dfs(v, u, d + 1, graph, l, m));
			l[u] += l[v];
			m[u] = min(m[u], m[v] + 1);
		}
	}

	if (flag) {
		l[u] = 1;
		m[u] = 0;
	}
	else if (m[u] <= d) {
		res = max(res, l[u]);
	}

	return res;
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

		vector<int> l(n, -1), m(n, 1e9);
		print(dfs(0, -1, 0, graph, l, m));
		// arrPrint(l);
		// arrPrint(m);
	}
}
