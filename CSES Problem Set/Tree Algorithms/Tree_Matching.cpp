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
vector<vector<int>> memo;

int dfs(int u, int p, bool canChoose) {
	if (memo[u][canChoose] != -1) {
		return memo[u][canChoose];
	}

	if (canChoose) {
		memo[u][true] = dfs(u, p, false);
		for (int v : graph[u]) {
			if (v != p) {
				memo[u][true] = max(memo[u][true], memo[u][false] - memo[v][true] + dfs(v, u, false) + 1);
			}
		}
	}
	else {
		memo[u][false] = 0;
		for (int v : graph[u]) {
			if (v != p) {
				memo[u][false] += dfs(v, u, true);
			}
		}
	}

	return memo[u][canChoose];
}

int main() {
	setup();
	
	int n; input(n);
	int inDegree[n];
	fill(inDegree, inDegree + n, 0);
	graph.resize(n);
	range(i, 0, n - 1) {
		int u, v;
		input(u);
		input(v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	memo = vector<vector<int>>(n, vector<int>(2, -1));
	print(dfs(0, -1, true));
}