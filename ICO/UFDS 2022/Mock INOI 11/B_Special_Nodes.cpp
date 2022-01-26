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
#define int long long

pair<vector<int>, vector<int>> dijkstras(vector<vector<pair<int, int>>> &graph, set<int> &special, int n, int s) {
	priority_queue<
		tuple<int, int, int>, 
		vector<tuple<int, int, int>>, 
		greater<tuple<int, int, int>>
	> pq;
	vector<int> dist(n, 1e15);
	vector<int> res(n, 0);
	dist[s] = 0;
	res[s] = special.count(s);
	pq.push({0, special.count(s), s});

	while (!pq.empty()) {
		int d, a, u;
		tie(d, a, u) = pq.top();
		pq.pop();

		if (d > dist[u] or (d == dist[u] and a < res[u])) {
			continue;
		}

		for (pair<int, int> p : graph[u]) {
			int v, w;
			tie(v, w) = p;
			if ((dist[u] + w == dist[v] and a + special.count(v) > res[v]) or 
				(dist[u] + w < dist[v])) {
				dist[v] = dist[u] + w;
				res[v] = a + special.count(v);
				pq.push({dist[v], res[v], v});
			}
		}
	}

	return {res, dist};
}

int32_t main() {
	setup();
	
	// Take input
	int n, m, k, s, e;
	input(n, m, k, s, e);
	s--;
	e--;
	vector<vector<pair<int, int>>> graph(n);
	while (m--) {
		int u, v, w;
		input(u, v, w);
		graph[u - 1].push_back({v - 1, w});
		graph[v - 1].push_back({u - 1, w});
	}
	vector<int> a(k);
	arrPut(a);
	set<int> special;
	for (int i : a) {
		special.insert(i - 1);
	}

	vector<int> specialS, specialE, distS, distE;
	tie(specialS, distS) = dijkstras(graph, special, n, s);
	tie(specialE, distE) = dijkstras(graph, special, n, e);
	range(i, 0, n) {
		if (distS[i] == 1e15 or distE[i] == 1e15 or distS[i] + distE[i] != distS[e]) {
			cout << "-1 ";
		}
		else {
			cout << specialS[i] + specialE[i] - special.count(i) << ' ';
		}
	}
}
