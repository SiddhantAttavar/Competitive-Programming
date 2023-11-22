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

int32_t main() {
	setup();

	int n, m, k;
	input(n, m, k);

	vector<vector<pair<int, int>>> graph(n);
	range(i, 0, m) {
		int u, v, w;
		input(u, v, w);

		graph[u - 1].push_back({v - 1, w});
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 0});
	vector<multiset<int>> d(n);
	d[0].insert(0);
	while (!pq.empty()) {
		int x, u;
		tie(x, u) = pq.top();
		pq.pop();

		if (x > *d[u].rbegin()) {
			continue;
		}

		for (pair<int, int> p : graph[u]) {
			if ((int) d[p.first].size() < k or (x + p.second) < *d[p.first].rbegin()) {
				d[p.first].insert(x + p.second);
				if ((int) d[p.first].size() > k) {
					multiset<int>::iterator i = d[p.first].end();
					i--;
					d[p.first].erase(i);
				}
				pq.push({x + p.second, p.first});
			}
		}
	}

	arrPrint(d[n - 1]);
}
