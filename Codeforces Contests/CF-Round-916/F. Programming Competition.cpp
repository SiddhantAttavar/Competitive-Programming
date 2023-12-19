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

void dfs(int u, vector<vector<int>> &graph, vector<int> &size, vector<int> &res) {
	int m = -1, y = 0;
	for (int v : graph[u]) {
		dfs(v, graph, size, res);
		size[u] += size[v];
		if (m == -1 or size[m] < size[v]) {
			m = v;
			y = size[v];
		}
	}

	if (m == -1) {
		res[u] = 1;
		return;
	}

	if (2 * y <= (size[u] - 1)) {
		res[u] = (size[u] - 1) % 2 + 1;
		return;
	}

	res[u] = max(0ll, res[m] - (size[u] - 1 - y)) + 1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> p(n - 1);
		arrPut(p);

		vector<vector<int>> graph(n);
		range(i, 0, n - 1) {
			graph[p[i] - 1].push_back(i + 1);
		}

		vector<int> size(n, 1);
		vector<int> res(n);
		dfs(0, graph, size, res);
		print((n - res[0]) / 2);
	}
}
