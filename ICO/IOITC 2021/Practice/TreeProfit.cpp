#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

int n, c, d;
vector<int> parent;
vector<int> a;
vector<int> leaves;
vector<vector<int>> graph;
vector<int> dist;

void dfs(int u) {
	if (graph[u].size() == 0) {
		leaves.push_back(u);
		return;
	}
	
	for (int v : graph[u]) {
		//If a[u] > 0, we can go down and come up
		if (a[u] > 0) {
			
		}
	}
}

int main() {
	setup();
	input(n, c, d);
	
	parent.resize(n, -1);
	a.resize(n);
	graph.resize(n);
	dist.resize(n, 0);

	range(i, 1, n) {
		input(parent[i]);
		parent[i]--;
		graph[parent[i]].push_back(i);
	}
	arrPut(a);

	dfs(0);

	if (d <= c) {
		//The simple path is the best path
		for (int u : leaves) {
			print(-c * dist[u]);
		}
		return 0;
	}

	//We must try to go down as many times as possible
	//For each node u we can go up and down a maximum of min(a[u], sum of a[v]) (v are the children)
	//For each time we go up and come back down, we get d - c coins
}