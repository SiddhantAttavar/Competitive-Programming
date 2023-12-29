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
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<pair<int, int>>> graph(n);
		range(i, 0, m) {
			int u, v, w;
			input(u, v, w);

			graph[u - 1].push_back({v - 1, w});
			graph[v - 1].push_back({u - 1, w});
		}

		vector<int> a(n);
		arrPut(a);

		vector<vector<int>> d(n, vector<int>(1001, 1e18));
		d[0][a[0]] = 0;
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		pq.push({0, {0, a[0]}});
		while (!pq.empty()) {
			int x = pq.top().first, u, s;
			tie(u, s) = pq.top().second;
			pq.pop();
			// print(x, u, s);

			if (x > d[u][s]) {
				continue;
			}

			if (s < 1000) {
				if (d[u][s + 1] > d[u][s]) {
					d[u][s + 1] = d[u][s];
					pq.push({d[u][s + 1], {u, s + 1}});
				}
			}

			if (a[u] < s) {
				if (d[u][a[u]] > d[u][s]) {
					d[u][a[u]] = d[u][s];
					pq.push({d[u][a[u]], {u, a[u]}});
				}
			}

			for (pair<int, int> p : graph[u]) {
				int v, w;
				tie(v, w) = p;
				// print(u, v, w, s, d[v][s], d[u][s]);
				if (d[v][s] > (d[u][s] + w * s)) {
					d[v][s] = d[u][s] + w * s;
					pq.push({d[v][s], {v, s}});
				}
			}
		}

		print(d[n - 1][1000]);
	}
}
