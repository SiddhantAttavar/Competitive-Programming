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

int MOD = 998244353;

vector<int> merge(vector<int> a, vector<int> b) {
	return {
		(a[0] + b[0]) % MOD,
		(a[1] + b[1]) % MOD,
		(a[2] + b[2] + a[1] * b[0]) % MOD
	};
}

void dfs(int u, vector<vector<pair<int, int>>> &graph, vector<vector<int>> &memo) {
	memo[u] = {0, 0, 0};
	for (pair<int, int> p : graph[u]) {
		int v, w;
		tie(v, w) = p;
		if (memo[v][0] == -1) {
			dfs(v, graph, memo);
		}
		memo[u] = merge(memo[u], merge({!w, w, 0}, memo[v]));
	}
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> s(n);

	vector<vector<pair<int, int>>> graph(n);
	range(i, 0, n) {
		input(s[i]);
		graph[i] = vector<pair<int, int>>(s[i]);
		range(j, 0, s[i]) {
			input(graph[i][j].first, graph[i][j].second);
			graph[i][j].first--;
		}
	}


	vector<vector<int>> memo(n, {-1, -1, -1});
	dfs(0, graph, memo);
	print(memo[0][2]);
}
