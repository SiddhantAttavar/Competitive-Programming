#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n, m;
vector<vector<int>> graph;
vector<int> path;
vector<bool> visited;

void dfs(int u) {
	visited[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
	path.push_back(u);
}

int main() {
	setup();
	cin >> n >> m;
	graph = vector<vector<int>>(n);
	visited = vector<bool>(n, false);

	range(i, 0, m) {
		input(int, u);
		input(int, v);
		graph[u - 1].push_back(v - 1);
	}

	range(i, 0, n) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	int ind[n];
	range(i, 0, n) {
		ind[path[i]] = i;
	}

	range(u, 0, n) {
		for (int v : graph[u]) {
			if (ind[v] >= ind[u]) {
				print("IMPOSSIBLE");
				return 0;
			}
		}
	}
	
	for (int i = n - 1; i >= 0; i--) {
		cout << path[i] + 1 << " ";
	}
}
