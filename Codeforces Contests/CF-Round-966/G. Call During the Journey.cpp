#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

bool check(vector<vector<pair<int, pair<int, int>>>> &graph, int t0, int t1, int t2, int m) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({m, 0});
	vector<int> d(graph.size(), 1e16);
	d[0] = m;
	while (!pq.empty()) {
		int x, u;
		tie(x, u) = pq.top();
		pq.pop();

		if (u == graph.size() - 1) {
			return x <= t0;
		}

		if (d[u] != x) {
			continue;
		}

		for (pair<int, pair<int, int>> p : graph[u]) {
			int y = x + p.second.second;
			if (x + p.second.first <= t1) {
				y = x + p.second.first;
			}
			else {
				y = min(y, max(x, t2) + p.second.first);
			}
			if (y < d[p.first]) {
				d[p.first] = y;
				pq.push({d[p.first], p.first});
			}
		}
	}
	return false;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		int t0, t1, t2;
		input(t0, t1, t2);

		vector<vector<pair<int, pair<int, int>>>> graph(n);
		range(i, 0, m) {
			int u, v, x, y;
			input(u, v, x, y);

			graph[u - 1].push_back({v - 1, {x, y}});
			graph[v - 1].push_back({u - 1, {x, y}});
		}

		int l = 0, r = t0, res = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(graph, t0, t1, t2, m)) {
				res = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		print(res);
	}
}
