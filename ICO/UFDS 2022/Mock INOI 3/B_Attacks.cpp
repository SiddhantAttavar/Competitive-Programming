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

int n, q;
vector<int> j;
vector<int> p, dp;
vector<vector<pair<int, int>>> graph;

void dfs(int u) {
	for (pair<int, int> v : graph[u]) {
		if (v.first != p[u]) {
			p[v.first] = u;
			dfs(v.first);
		}
	}
}

int32_t main() {
	setup();

	input(n, q);

	graph.resize(n);
	range(i, 0, n - 1) {
		int u, v, w;
		input(u, v, w);
		graph[u - 1].push_back({v - 1, w});
		graph[v - 1].push_back({u - 1, w});
	}

	j.resize(n);
	arrPut(j);

	p.resize(n, -1);
	dp = vector<int>(j);
	dfs(0);

	vector<int> res[0];

	while (q--) {
		int e;
		input(e);

		vector<bool> visited(n, false);
		int res = 0;
		range(i, 0, n) {
			if (visited[i]) {
				continue;
			}

			visited[i] = true;
			queue<int> d;
			d.push(i);
			int x = 0;
			while (!d.empty()) {
				int u = d.front();
				d.pop();
				x += j[u];

				for (pair<int, int> p : graph[u]) {
					if (p.second <= e and !visited[p.first]) {
						visited[p.first] = true;
						d.push(p.first);
					}
				}
			}
			res = max(res, x);
		}

		print(res);
	}
}
