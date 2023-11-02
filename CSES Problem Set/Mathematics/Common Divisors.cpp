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

int dfs(int u, int p, vector<vector<int>> &graph) {
	int res = 0;
	if (graph[u].size() > 1) {
		res = u;
	}

	for (int v : graph[u]) {
		if (v != p) {
			res = max(res, dfs(v, u, graph));
		}
	}

	return res;
}

int32_t main() {
	setup();

	int N = 1e6;
	vector<int> spf(N + 1);
	range(i, 0, N + 1) {
		spf[i] = i;
	}

	for (int i = 4; i <= N; i += 2) {
		spf[i] = 2;
	}

	for (int i = 3; i * i <= N; i++) {
		if (spf[i] == i) {
			for (int j = 2 * i; j <= N; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}

	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	vector<vector<int>> graph(N + 1);
	for (int i : a) {
		while (i > 1) {
			graph[i / spf[i]].push_back(i);
			i /= spf[i];
		}
	}

	print(dfs(1, -1, graph));
}
