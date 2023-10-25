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

void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis, vector<vector<int>> &comp) {
	comp.back().push_back(u);
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis, comp);
		}
	}
}

vector<int> a;
int MOD = (int) 1e9 + 7;

int modPow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}

		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
}

int modDiv(int a, int b) {
	return (a * modPow(b, MOD - 2)) % MOD;
}

int modFact(int x) {
	int res = 1;
	range(i, 2, x + 1) {
		res = (res * i) % MOD;
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<int>> graph(n);
		range(i, 0, m) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		a.resize(n);
		arrPut(a);

		vector<vector<int>> comp;
		vector<bool> vis(n, false);
		int res = 1;
		range(i, 0, n) {
			if (vis[i]) {
				continue;
			}

			comp.push_back({});
			dfs(i, graph, vis, comp);
			sort(comp.back().begin(), comp.back().end(), [](int x, int y) {
				return a[x] < a[y];
			});


			int c = 1;
			range(j, 1, (int) comp.back().size()) {
				if (a[comp.back()[j]] != a[comp.back()[j - 1]]) {
					res = (res * modFact(c)) % MOD;
					c = 0;
				}
				c++;
			}
			res = (res * modFact(c)) % MOD;
		}

		res = (res * modFact(n)) % MOD;
		for (vector<int> v : comp) {
			res = modDiv(res, modFact(v.size()));
		}

		print(res);
	}
}
