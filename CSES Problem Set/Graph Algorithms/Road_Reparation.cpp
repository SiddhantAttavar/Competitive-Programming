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

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<pair<int, int>>> graph(n);
	range(i, 0, m) {
		int u, v, w;
		input(u, v, w);

		graph[u - 1].push_back({v - 1, w});
		graph[v - 1].push_back({u - 1, w});
	}

	vector<bool> d(n, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int res = 0, c = n;

	pq.push({0, 0});
	while (!pq.empty()) {
		int x, u;
		tie(x, u) = pq.top();
		pq.pop();

		if (d[u]) {
			continue;
		}

		c--;
		res += x;
		d[u] = true;

		for (pair<int, int> p : graph[u]) {
			if (!d[p.first]) {
				pq.push({p.second, p.first});
			}
		}
	}

	if (c) {
		print("IMPOSSIBLE");
	}
	else {
		print(res);
	}
}
