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

int h = (int) log2(500) + 1;

void dfs(int u, int p, vector<vector<int>> &graph, vector<int> &d, vector<vector<int>> &par) {
	for (int v : graph[u]) {
		if (v != p) {
			d[v] = d[u] + 1;
			par[v][0] = u;
			range(i, 1, h) {
				if (par[u][i - 1] == -1) {
					break;
				}
				par[v][i] = par[par[u][i - 1]][i - 1];
			}

			dfs(v, u, graph, d, par);
		}
	}
}

int lca(int u, int v, vector<vector<int>> &par, vector<int> &d) {
	if (d[u] < d[v]) {
		swap(u, v);
	}

	// print(u, v);
	// cout.flush();

	for (int i = h - 1; i >= 0; i--) {
		if (par[u][i] != -1 and d[par[u][i]] >= d[v]) {
			u = par[u][i];
		}
	}

	// print(u, v);
	// cout.flush();

	if (u == v) {
		return u;
	}

	for (int i = h - 1; i >= 0; i--) {
		if (par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}

	return par[u][0];
}

int32_t main() {
	// setup();
	int n, k;
	input(n, k);

	vector<vector<int>> res(n, vector<int>(n, 0));
	while (k--) {
		vector<vector<int>> graph(n);

		range(i, 0, n - 1) {
			int u, v;
			input(u, v);
			u--;
			v--;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		vector<vector<int>> par(n, vector<int>(h, -1));
		vector<int> d(n, 0);

		dfs(0, -1, graph, d, par);

		arrPrint(d);
		cout.flush();

		range(u, 0, n) {
			range(v, 0, n) {
				int x = lca(u, v, par, d);
				res[u][v] += d[u] - d[x] + d[v] - d[x];
			}
		}
		// cout << "debug" << endl;
	}

	range(i, 0, n) {
		arrPrint(res[i]);
	}
} 
