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
const int MOD = (int) 1e9 + 7; //998244353

vector<int> dijkstras(vector<vector<pair<int, int>>> &graph, int u) {
	int n = graph.size() / 2;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> d(2 * n, 1e18);
	d[u] = 0;
	pq.push({0, u});
	while (!pq.empty()) {
		int x, u;
		tie(x, u) = pq.top();
		pq.pop();

		if (d[u] < x) {
			continue;
		}

		for (pair<int, int> p : graph[u]) {
			int v, w;
			tie(v, w) = p;
			if (x + w < d[v]) {
				d[v] = x + w;
				pq.push({d[v], v});
			}
		}
	}
	return d;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, h;
		input(n, m, h);

		vector<int> a(h);
		arrPut(a);

		vector<vector<pair<int, int>>> graph(2 * n);
		range(i, 0, m) {
			int u, v, w;
			input(u, v, w);

			graph[u - 1].push_back({v - 1, w});
			graph[v - 1].push_back({u - 1, w});
			graph[n + u - 1].push_back({n + v - 1, w / 2});
			graph[n + v - 1].push_back({n + u - 1, w / 2});
		}

		for (int i : a) {
			graph[i - 1].push_back({n + i - 1, 0});
		}

		range(i, 0, n) {
			graph[n + i].push_back({i, 0});
		}

		vector<int> x = dijkstras(graph, 0), y = dijkstras(graph, n - 1);
		if (x[n - 1] == 1e18) {
			print(-1);
			continue;
		}

		int res = 1e18;
		range(i, 0, 2 * n) {
			res = min(res, max(x[i], y[i]));
		}
		print(res);
	}
}
