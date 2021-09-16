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

vector<vector<pair<int, int>>> graph;
vector<int> inDegree, outDegree;
vector<bool> visited;
vector<int> path;

void dfs(int u) {
	for (pair<int, int> p : graph[u]) {
		int v, i;
		tie(v, i) = p;
		if (!visited[i]) {
			visited[i] = true;
			dfs(v);
		}
	}

	path.push_back(u + 1);
}

int main() {
	setup();

	int n, m;
	input(n);
	input(m);
	
	graph.resize(n);
	inDegree = vector<int>(n, 0);
	outDegree = vector<int>(n, 0);
	visited = vector<bool>(m, false);

	range(i, 0, m) {
		int u, v;
		input(u);
		input(v);
		
		u--;
		v--;

		graph[u].push_back({v, i});
		inDegree[v]++;
		outDegree[u]++;
	}

	range(i, 1, n - 1) {
		if (inDegree[i] != outDegree[i]) {
			print("IMPOSSIBLE");
			return 0;
		}
	}

	if (inDegree[0] + 1 != outDegree[0] || inDegree[n - 1] != outDegree[n - 1] + 1) {
		print("IMPOSSIBLE");
		return 0;
	}

	dfs(0);
	reverse(path.begin(), path.end());

	if (path.size() < m + 1) {
		print("IMPOSSIBLE");
	}
	else {
		arrPrint(path);
	}
}