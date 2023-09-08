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

int MOD = 998244353;
vector<int> st;
int t = 0;

void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &topo) {
	visited[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v, graph, visited, topo);
		}
	}
	topo.push_back(u);
}

int modPow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}

		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int modDiv(int a, int b) {
	return (a * modPow(b, MOD - 2)) % MOD;
}

int32_t main() {
	setup();
	int n, m;
	input(n, m);

	vector<int> c(n);
	arrPut(c);

	vector<vector<int>> graph(n);
	range(i, 0, m) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
	}

	vector<bool> visited(n, false);
	vector<int> topo;
	range(i, 0, n) {
		if (!visited[i]) {
			dfs(i, graph, visited, topo);
		}
	}
	reverse(topo.begin(), topo.end());

	int res = 0;
	fill(visited.begin(), visited.end(), false);
	vector<int> par(n, -1);
	for (int i : topo) {
		if (visited[i]) {
			continue;
		}

		set<int> cycle;
		cycle.insert(i);
		// dfs(i, graph, visited, cycle);

		queue<int> q;
		q.push(i);
		visited[i] = true;
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : graph[u]) {
				// print("edges:", u, v);
				if (!visited[v]) {
					visited[v] = true;
					par[v] = u;
					q.push(v);
				}
				else if (cycle.count(v)) {
					int j = u;
					// print('a', u);
					while (j != -1) {
						if (cycle.count(j)) {
							break;
						}
						cycle.insert(j);
						j = par[j];
					}
				}
			}
		}

		// arrPrint(cycle);
		// arrPrint(par);

		int x = 0;
		for (int j : cycle) {
			x = (x + c[j]) % MOD;
		}
		res = (res + modDiv(x, cycle.size())) % MOD;
	}

	print(res);
}
