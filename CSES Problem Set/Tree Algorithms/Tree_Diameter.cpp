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
vector<int> dist;

void dfs(int u, int p) {
	for (int v : graph[u]) {
		if (v != p) {
			dist[v] = dist[u] + 1;
			dfs(v, u);
		}
	}
}

int main() {
	setup();
	
	int n; input(n);
	
	graph.resize(n);
	dist.resize(n);
	range(i, 1, n) {
		int u, v;
		input(u);
		input(v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	dist[0] = 0;
	dfs(0, -1);

	int farthestNode = max_element(dist.begin(), dist.end()) - dist.begin();
	
	dist[farthestNode] = 0;
	dfs(farthestNode, -1);

	print(*max_element(dist.begin(),dist.end()));
}