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

bool dfs1(int u, int p, vector<vector<int>> &graph, vector<int> &a) {
	a[u] = graph[u].size() == 1 and graph[u][0] == p;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		a[u] += !dfs1(v, u, graph, a);
	}

	return a[u];
}

void dfs2(int u, int p, vector<vector<int>> &graph, vector<int> &a, vector<bool> &b) {
	if (!a[u] and p != -1) {
		b[u] = a[p] - 1;
	}
	else {
		b[u] = a[u];
	}

	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		dfs2(v, u, graph, a, b);
	}
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<int>> graph(n);
	range(i, 0, n - 1) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> a(n);
	dfs1(0, -1, graph, a);

	vector<bool> b(n);
	dfs2(0, -1, graph, a, b);

	for (bool i : b) {
		if (i) {
			print("Alice");
			return 0;
		}
	}

	print("Bob");
}
