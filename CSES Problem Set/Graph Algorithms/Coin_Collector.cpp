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

vector<int> k;
vector<vector<int>> graph, revGraph;
vector<bool> visited;
vector<int> nodes;
vector<int> comp;
vector<ll> groupSize;
vector<vector<int>> finGraph;
vector<ll> dp;
int compSize = 0;

void topoSort(int u) {
	visited[u] = true;

	for (int v : graph[u]) {
		if (!visited[v]) {
			topoSort(v);
		}
	}

	nodes.push_back(u);
}

void group(int u) {
	comp[u] = compSize;
	groupSize[comp[u]] += k[u];

	for (int v : revGraph[u]) {
		if (comp[v] == -1) {
			group(v);
		}
	}
}

ll solve(int u) {
	if (dp[u] > 0) {
		return dp[u];
	}

	dp[u] = groupSize[u];
	for (int v : finGraph[u]) {
		dp[u] = max(dp[u], solve(v) + groupSize[u]);
	}

	return dp[u];
}

int main() {
	setup();
	
	//Take input
	int n, m;
	input(n);
	input(m);
	k.resize(n); arrPut(k);

	//Initialize graph
	graph.resize(n);
	revGraph.resize(n);
	range(i, 0, m) {
		int u, v;
		input(u);
		input(v);

		u--;
		v--;

		graph[u].push_back(v);
		revGraph[v].push_back(u);
	}

	//Do topological sort of the graph
	visited = vector<bool>(n, false);
	range(i, 0, n) {
		if (!visited[i]) {
			topoSort(i);
		}
	}
	reverse(nodes.begin(), nodes.end());
	
	//Assign a group number and compute the size to each SCC
	comp = vector<int>(n, -1);
	groupSize = vector<ll>(n, 0);
	for (int u : nodes) {
		if (comp[u] == -1) {
			group(u);
			compSize++;
		}
	}

	//Create the new graph
	finGraph.resize(compSize);
	range(u, 0, n) {
		for (int v : graph[u]) {
			if (comp[u] != comp[v]) {
				finGraph[comp[u]].push_back(comp[v]);
			}
		}
	}

	//Find the longest path in the finGraph
	ll res = 0;
	dp = vector<ll>(compSize, 0);
	range(i, 0, compSize) {
		res = max(res, solve(i));
	}

	print(res);
}