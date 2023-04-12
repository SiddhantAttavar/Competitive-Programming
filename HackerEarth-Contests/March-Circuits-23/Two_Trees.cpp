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
vector<vector<pair<int, int>>> graph;
vector<int> d, l, a;
const int INF = 1e18;

void dfs1(int u) {
	for (pair<int, int> p : graph[u]) {
		int v, w;
		tie(v, w) = p;
		if (l[v] == INF and v < n) {
			l[v] = l[u] + 1;
			dfs1(v);
		}
	}
}

int32_t main() {
	setup();

	input(n);

	graph.resize(2 * n);
	range(i, 0, n - 1) {
		int u, v, w;
		input(u, v, w);

		graph[u - 1].push_back({v - 1, w});
		graph[n + u - 1].push_back({n + v - 1, 2 * w});
	}

	a.resize(n);
	range(i, 0, n) {
		input(a[i]);
		graph[i].push_back({n + i, a[i]});
		graph[n + i].push_back({i, a[i]});
	}

	l.resize(2 * n, INF);
	l[0] = 0;
	dfs1(0);
	range(i, 0, n) {
		l[n + i] = l[i];
	}

	d.resize(2 * n, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, n});
	d[n] = 0;
	while (!pq.empty()) {
		int x, u;
		tie(x, u) = pq.top();
		pq.pop();

		for (pair<int, int> p : graph[u]) {
			int v, w;
			tie(v, w) = p;
			if (d[u] + w < d[v]) {
				// print(u, v, w);
				d[v] = d[u] + w;
				pq.push({d[u] + w, v});
			}
		}
	}

	arrPrint(d);

	input(q);
	while (q--) {
		int u, v;
		input(u, v);

		print(d[n + u - 1] - d[n + v - 1]);
	}
}
