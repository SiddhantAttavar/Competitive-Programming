#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &topo) {
	visited[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v, graph, visited, topo);
		}
	}
	topo.push_back(u);
}

vector<int> bfs(int n, vector<vector<int>> &graph, vector<int> &start) {
	vector<int> d(n, 1e9);
	queue<int> q;

	for (int u : start) {
		q.push(u);
		d[u] = 0;
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : graph[u]) {
			if (d[v] == (int) 1e9) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}

	return d;
}

int32_t main() {
	setup();

	int n, m, k;
	input(n, m, k);

	vector<int> o(m), c(k);
	arrPut(o);
	arrPut(c);
	range(i, 0, m) {
		o[i]--;
	}
	range(i, 0, k) {
		c[i]--;
	}

	/*
	vector<bool> o(n, false);
	range(i, 0, m) {
		int u;
		input(u);
		o[u - 1] = true;
	}


	vector<bool> c(n, false);
	range(i, 0, k) {
		int u;
		input(u);
		c[u - 1] = true;
	}
	*/

	vector<vector<int>> graph(n);
	vector<vector<int>> revGraph(n);
	range(i, 0, n) {
		int x;
		input(x);
		graph[i].resize(x);
		arrPut(graph[i]);
		range(j, 0, x) {
			graph[i][j]--;
		}

		for (int j : graph[i]) {
			revGraph[j].push_back(i);
		}
	}

	/* queue<int> q;
	vector<int> d(n, 1e9);
	vector<vector<int>> dag(n);
	q.push(0);
	d[0] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : graph[u]) {
			if (d[v] == (int) 1e9) {
				dag[u].push_back(v);
				d[v] = d[u] + 1;
				q.push(v);
			}
			else if (d[v] == d[u] + 1) {
				dag[u].push_back(v);
			}
		}
	}

	vector<int> a(n, 1e9), b(n, 1e9);
	vector<int> topo;
	vector<bool> visited(n, false);
	dfs(0, dag, visited, topo);

	// reverse(topo.begin(), topo.end());
	// reverse(topo.begin(), topo.end());

	for (int u : topo) {
		if (o[u]) {
			a[u] = 0;
		}
		if (c[u]) {
			b[u] = 0;
		}

		for (int v : dag[u]) {
			a[u] = min(a[u], a[v] + 1);
			b[u] = min(b[u], b[v] + 1);
		}
	}
	*/

	vector<int> root = {0};
	vector<int> d = bfs(n, graph, root);
	vector<int> a = bfs(n, revGraph, c);
	vector<int> b = bfs(n, revGraph, o);
	// arrPrint(d);
	// arrPrint(a);
	// arrPrint(b);

	int res = 1e9;
	range(i, 0, n) {
		res = min(res, d[i] + a[i] + b[i]);
	}
	if (res == (int) 1e9) {
		print("impossible");
	}
	else {
		print(res);
	}
}

