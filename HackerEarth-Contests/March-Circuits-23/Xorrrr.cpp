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

int n;
vector<vector<int>> graph;
vector<int> s;

int dfs(int u, int p) {
	int res = 0;
	for (int v : graph[u]) {
		if (v != p) {
			res ^= dfs(v, u);
			s[u] += s[v];
			
			if ((s[v] & 1) and ((n - s[v]) & 1)) {
				res ^= (u + v + 2);
			}
		}
	}

	return res;
}

int32_t main() {
	setup();

	input(n);

	graph.resize(n);
	range(i, 0, n - 1) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	s.resize(n, 1);
	print(dfs(0, -1));
}
