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

bool dfs(int u, int c, vector<vector<int>> &graph, vector<int> &color) {
	color[u] = c;
	for (int v : graph[u]) {
		if (color[v] == 0) {
			if (!dfs(v, 3 - c, graph, color)) {
				return false;
			}
		}
		else if (color[v] == color[u]) {
			return false;
		}
	}

	return true;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<int>> graph(n);
	range(i, 0, m) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> c(n);
	range(i, 0, n) {
		if (!c[i]) {
			if (!dfs(i, 1, graph, c)) {
				print("IMPOSSIBLE");
				arrPrint(c);
				return 0;
			}
		}
	}

	arrPrint(c);
}
