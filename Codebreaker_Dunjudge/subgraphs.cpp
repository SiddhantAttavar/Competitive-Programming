// https://codebreaker.xyz/problem/subgraphs
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int u) {
	visited[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(graph, visited, v);
		}
	}
}

int32_t main() {
	setup();
	int n, m;
	input(n, m);
	vector<vector<int>> graph(n);
	while (m--) {
		int u, v;
		input(u, v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<bool> visited(n);
	int res = 0;
	range(i, 0, n) {
		if (!visited[i]) {
			res++;
			dfs(graph, visited, i);
		}
	}
	print(res);
}
