#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &outVar : var) {cin >> outVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

const int MAX_N = 2500;
vector<vector<int>> g1, g2;
vector<tuple<int, int, int>> edges;
vector<bool> v1, v2;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int u) {
	visited[u] = true;

	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(graph, visited, v);
		}
	}
}

int main() {
	setup();
	
	int n, m;
	input(n);
	input(m);

	v1 = vector<bool>(n, false);
	v2 = vector<bool>(n, false);
	
	g1.resize(n);
	g2.resize(n);

	//Take input
	range(i, 0, m) {
		int u, v;
		ll w;
		input(u);
		input(v);
		input(w);

		g1[u - 1].push_back(v - 1);
		g2[v - 1].push_back(u - 1);
		edges.push_back({u - 1, v - 1, -w});
	}

	dfs(g1, v1, 0);
	dfs(g2, v2, n - 1);

	ll distance[n];
	fill(distance, distance + n, 1e15);
	distance[0] = 0;

	//Find the min distance
	range(i, 0, n - 1) {
		for (tuple<int, int, int> t : edges) {
			int u, v, w; tie(u, v, w) = t;
			distance[v] = min(distance[v], distance[u] + w);
		}
	}

	for (tuple<int, int, int> t : edges) {
		int u, v, w; tie(u, v, w) = t;
		if ((distance[u] + w) < distance[v] && v1[v] && v2[v]) {
			print(-1);
			return 0;
		}
	}

	print(-distance[n - 1]);
}