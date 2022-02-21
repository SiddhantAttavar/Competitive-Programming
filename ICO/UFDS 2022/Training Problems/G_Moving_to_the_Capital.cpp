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

int dfs(int u, vector<vector<int>> &graph, vector<int> &a, vector<int> &d) {
	a[u] = d[u];
	for (int v : graph[u]) {
		if (a[v] == 1e9 and d[v] > d[u]) {
			a[u] = min(a[u], dfs(v, graph, a, d));
		}
		else {
			a[u] = min(a[u], d[v]);
		}
	}
	return a[u];
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<int>> graph(n);
		range(i, 0, m) {
			int u, v;
			input(u, v);
			graph[u - 1].push_back(v - 1);
		}

		vector<int> d(n, -1);
		queue<int> q;
		q.push(0);
		d[0] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : graph[u]) {
				if (d[v] == -1) {
					d[v] = d[u] + 1;
					q.push(v);
				}
			}
		}

		vector<int> a(n, 1e9);
		dfs(0, graph, a, d);

		arrPrint(a);
	}
}
