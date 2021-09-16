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
#define int ll

vector<int> f;
vector<vector<int>> graph;
vector<vector<int>> dist;
int curr;

void dfs(int u, int p) {
	for (int v : graph[u]) {
		if (v != p) {
			dist[curr][v] = dist[curr][u] + 1;
			dfs(v, u);
		}
	}
}

void subTask1(int n, int k, int a) {
	dist.clear();
	dist = vector<vector<int>>(n, vector<int>(n));
	graph.clear();
	graph.resize(n);
	f.resize(k);
	arrPut(f);
	range(i, 0, k) {
		f[i]--;
	}
	range(i, 0, n - 1) {
		int u, v; input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	range(i, 0, n) {
		curr = i;
		dist[i][i] = 0;
		dfs(i, -1);
	}

	pair<int, int> res[n];
	range(i, 0, n) {
		int x = -1e9, y = -1e9;
		for (int u : f) {
			int m = dist[a][u] - dist[i][u];
			if (m > x) {
				x = m;
				y = u;
			}
		}
		res[i] = {y + 1, x};
	}
	for (pair<int, int> p : res) {
		cout << p.second << ' ';
	}
	cout << endl;
	for (pair<int, int> p : res) {
		cout << p.first << ' ';
	}
	cout << endl;
}

signed main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k, a; input(n, k, a);
		a--;

		if (n <= 2000) {
			subTask1(n, k, a);
			continue;
		}

		f.resize(k);
		arrPut(f);
		range(i, 0, n - 1) {
			int u, v; input(u, v);
		}

		int l = *min_element(f.begin(), f.end()) - 1;
		int r = *max_element(f.begin(), f.end()) - 1;
		pair<int, int> res[n];
		if (l <= a && a <= r) {
			range(i, 0, l) {
				res[i] = {(a - l) - (l - i), l + 1};
			}
			range(i, l, a) {
				res[i] = {abs(a - i), l + 1};
			}
			range(i, a, r + 1) {
				res[i] = {abs(a - i), r + 1};
			}
			range(i, r + 1, n) {
				res[i] = {(r - a) - (i - r), r + 1};
			}
		}
		else if (a < l) {
			range(i, 0, n) {
				res[i] = {(r - a) - abs(r - i), r + 1};
			}
		}
		else {
			range(i, 0, n) {
				res[i] = {(a - l) - abs(i - l), l + 1};
			}
		}
		for (pair<int, int> p : res) {
			cout << p.first << ' ';
		}
		cout << endl;
		for (pair<int, int> p : res) {
			cout << p.second << ' ';
		}
		cout << endl;
	}
}