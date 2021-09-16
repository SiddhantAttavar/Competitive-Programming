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
vector<int> compSize;
vector<bool> visited;

void dfs(int u) {
	compSize[compSize.size() - 1]++;
	visited[u] = true;

	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, m;
		input(n);
		input(m);

		graph = vector<vector<int>>(n);
		compSize.clear();
		visited = vector<bool>(n, false);
		while (m--) {
			int u, v;
			input(u);
			input(v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		range(i, 0, n) {
			if (!visited[i]) {
				compSize.push_back(0);
				dfs(i);
			}
		}

		ll res = 1;
		for (int i : compSize) {
			res = (res * i) % MOD;
		}
		print(compSize.size() << " " << res);
	}
}