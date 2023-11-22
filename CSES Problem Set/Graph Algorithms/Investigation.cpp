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

	const int MOD = (int) 1e9 + 7;

	int n, m;
	input(n, m);

	vector<vector<pair<int, int>>> graph(n);
	range(i, 0, m) {
		int u, v, w;
		input(u, v, w);

		graph[u - 1].push_back({v - 1, w});
		// graph[v - 1].push_back({u - 1, w});
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> a(n, 0), b(n, m), c(n, 0), d(n, 1e18);
	pq.push({0, 0});
	d[0] = 0;
	c[0] = 1;
	b[0] = 0;
	a[0] = 0;
	while (!pq.empty()) {
		int x, u;
		tie(x, u) = pq.top();
		pq.pop();

		if (x != d[u]) {
			continue;
		}

		for (pair<int, int> p : graph[u]) {
			int v, w;
			tie(v, w) = p;
			if ((x + w) < d[v]) {
				a[v] = a[u] + 1;
				b[v] = b[u] + 1;
				c[v] = c[u];
				d[v] = x + w;
				pq.push({d[v], v});
			}
			else if ((x + w) == d[v]) {
				a[v] = max(a[v], a[u] + 1);
				b[v] = min(b[v], b[u] + 1);
				c[v] = (c[v] + c[u]) % MOD;
			}
		}
	}

	// arrPrint(d);

	print(d[n - 1], c[n - 1], b[n - 1], a[n - 1]);
}
