#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T &x) {cin >> x;}
template<typename T, typename... S> inline void input(T &x, S&... y) {cin >> x; input(y ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... y) {cout << x << ' '; print(y ...);}
#define arrPut(x) for (auto &i : x) {cin >> i;}
#define arrPrint(x) for (auto i : x) {cout << i << ' ';} cout << '\n'
#define range(i, j, n) for (int i = j; i < n; i++)
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

void subtask2(int n, int m) {
	int res = 0;
	while (m--) {
		int u, v, w;
		input(u, v, w);
		res += w;
	}
	print(res);
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	if (n == m) {
		subtask2(n, m);
		return 0;
	}

	vector<tuple<int, int, int>> edges(m);
	vector<vector<pair<int, int>>> graph(n);
	range(i, 0, m) {
		int u, v, w;
		input(u, v, w);
		u--;
		v--;
		edges[i] = {u, v, w};
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	int res = 1e18;
	range(i, 0, n) {
		vector<int> dist(n, 1e18);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		dist[i] = 0;
		pq.push({0, i});
		while (!pq.empty()) {
			int d, u;
			tie(d, u) = pq.top();
			pq.pop();

			for (pair<int, int> p : graph[i]) {
				int v, w;
				tie(v, w) = p;
				if (d + w < dist[v]) {
					dist[v] = d + w;
					pq.push({dist[v], v});
				}
				else {
					res = min(res, d + w + dist[v]);
				}
			}
		}
	}

	print(res);
}
