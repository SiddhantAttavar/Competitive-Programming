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
vector<bool> visited, onStack;

bool dfs(int u) {
	visited[u] = true;
	onStack[u] = true;
	for (int v : graph[u]) {
		if (onStack[v]) {
			path.push_back(u);
			onStack[u] = false;
			onStack[v] = false;
			return true;
		}
		else if (!visited[v]) {
			if (dfs(v)) {
				if (onStack[u]) {
					path.push_back(u);
					onStack[u] = false;
					return true;
				}
				else {
					path.push_back(u);
					return false;
				}
			}
			if (!path.empty()) {
				return false;
			}
		}
	}
	onStack[u] = false;
	return false;
}

int main() {
	setup();
	cin >> n >> m;

	onStack = vector<bool>(n + 1, false);
	visited = vector<bool>(n + 1, false);
	graph = vector<vector<int>>(n + 1);
	range(i, 0, m) {
		input(int, u);
		input(int, v);
		graph[u].push_back(v);
	}

	range(i, 1, n + 1) {
		dfs(i);
		if (!path.empty()) {
			break;
		}
	}

	if (path.empty()) {
		print("IMPOSSIBLE");
	}
	else {
		print(path.size() + 1);
		for (int i = path.size() - 1; i >= 0; i--) {
			cout << path[i] << " ";
		}
		print(path[path.size() - 1]);
	}
}
