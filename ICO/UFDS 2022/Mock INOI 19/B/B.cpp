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
	vector<vector<tuple<int, int, int>>> graph(n);
	range(i, 0, m) {
		int u, v, w;
		input(u, v, w);
		u--;
		v--;
		edges[i] = {u, v, w};
		graph[u].push_back({v, w, i});
		graph[v].push_back({u, w, i});
	}

	int res = 1e18;
	range(k, 0, m) {
		int u, v, w;
		tie(u, v, w) = edges[k];

		vector<int> dist(n, 1e18);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		dist[u] = 0;
		pq.push({0, u});
		while (!pq.empty()) {
			int d, i;
			tie(d, i) = pq.top();
			pq.pop();

			if (d >= res) {
				break;
			}

			if (i == v) {
				// print(d, w, i, v);
				res = d + w;
				break;
			}

			for (tuple<int, int, int> t : graph[i]) {
				int j, e, x;
				tie(j, e, x) = t;
				if (x != k and dist[i] + e < dist[j]) {
					dist[j] = dist[i] + e;
					pq.push({dist[j], j});
				}
			}
		}
	}

	print(res);
}
