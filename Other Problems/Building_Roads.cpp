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
vector<bool> visited;
vector<int> components;

void dfs(int u) {
	visited[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main() {	
	setup();
	cin >> n >> m;
	
	graph = vector<vector<int>>(n + 1);
	visited = vector<bool>(n + 1, false);
	range(i, 0, m) {
		input(int, u);
		input(int, v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	range(i, 1, n + 1) {
		if (!visited[i]) {
			components.push_back(i);
			dfs(i);
		}
	}

	print(components.size() - 1);
	range(i, 0, components.size() - 1) {
		cout << components[i] << " " << components[i + 1] << endl;
	}
}