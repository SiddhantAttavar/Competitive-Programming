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

	bool flag = false;
	for (int u : topoSort) {
		if (u == n - 1) {
			flag = true;
			break;
		}
	}

	if (!flag) {
		print("IMPOSSIBLE");
		return 0;
	}
	
	reverse(topoSort.begin(), topoSort.end());

	int distance[n] = {0};
	fill(distance + 1, distance + n, INT_MIN);

	int prev[n] = {-1};

	for (int u : topoSort) {
		for (int v : graph[u]) {
			if (distance[u] + 1 > distance[v]) {
				distance[v] = distance[u] + 1;
				prev[v] = u;
			}
		}
	}

	print(distance[n - 1] + 1);
	
	vector<int> path = {n};
	int curr = n - 1;
	while (curr != 0) {
		curr = prev[curr];
		path.push_back(curr + 1);
	}

	reverse(path.begin(), path.end());
	arrPrint(path);
}