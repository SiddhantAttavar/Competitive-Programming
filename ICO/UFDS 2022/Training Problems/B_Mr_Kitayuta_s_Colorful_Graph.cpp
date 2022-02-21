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

bool dfs(int u, int e, int c, vector<vector<pair<int, int>>> &graph, set<int> &visited) {
	if (u == e) {
		return true;
	}
	visited.insert(u);
	for (pair<int, int> p : graph[u]) {
		int v, d;
		tie(v, d) = p;
		if (!visited.count(v) and c == d) {
			if (dfs(v, e, c, graph, visited)) {
				return true;
			}
		}
	}
	return false;
}

int32_t main() {
	setup();
	
	int n, m;
	input(n, m);

	vector<vector<pair<int, int>>> graph(n);
	range(i, 0, m) {
		int u, v, c;
		input(u, v, c);

		graph[u - 1].push_back({v - 1, c - 1});
		graph[v - 1].push_back({u - 1, c - 1});
	}

	int q;
	input(q);
	while (q--) {
		int u, v;
		input(u, v);

		int res = 0;
		set<int> visited;
		range(i, 0, m) {
			visited.clear();
			res += dfs(u - 1, v - 1, i, graph, visited);
		}
		print(res);
	}
}
