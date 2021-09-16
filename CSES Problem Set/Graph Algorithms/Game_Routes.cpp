#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

vector<vector<int>> graph;
vector<int> topoSort;
vector<bool> visited;

void dfs(int u) {
	visited[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
	topoSort.push_back(u);
}

int main() {
	setup();
	
	int n, m;
	input(n);
	input(m);

	graph.resize(n);
	visited = vector<bool>(n, false);

	range(i, 0, m) {
		int u, v;
		input(u);
		input(v);
		graph[u - 1].push_back(v - 1);
	}

	dfs(0);

	reverse(topoSort.begin(), topoSort.end());

	int dp[n] = {1};
	fill(dp + 1, dp + n, 0);

	for (int u : topoSort) {
		for (int v : graph[u]) {
			dp[v] = (dp[v] + dp[u]) % MOD;
		}
	}

	print(dp[n - 1]);
}