#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = 998244353;

void dfs(int u, vector<pair<pair<int, int>, int>> &graph, vector<int> &res) {
	// print(u);
	// cout.flush();
	if (graph[u].first.first != -2) {
		dfs(graph[u].first.first, graph, res);
	}
	res.push_back(graph[u].second);
	if (graph[u].first.second != -2) {
		dfs(graph[u].first.second, graph, res);
	}
}

int modDiv(int a, int b) {
	int inv = 1, c = MOD - 2;
	while (c) {
		if (c & 1) {
			inv = (inv * b) % MOD;
		}

		b = (b * b) % MOD;
		c >>= 1;
	}
	return (a * inv) % MOD;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, c;
		input(n, c);

		vector<pair<pair<int, int>, int>> graph(n);
		range(i, 0, n) {
			input(graph[i].first.first, graph[i].first.second, graph[i].second);
			graph[i].first.first--;
			graph[i].first.second--;
		}

		vector<int> v;
		dfs(0, graph, v);

		vector<int> pref(n, 1);
		pref[0] = max(1ll, v[0]);
		range(i, 1, n) {
			pref[i] = max(pref[i - 1], v[i]);
		}

		vector<pair<int, int>> b;
		int y = 1, k = 0;
		range(i, 0, n) {
			if (v[i] == -1) {
				k++;
			}
			else {
				b.push_back({v[i] - y, k});
				y = v[i];
				k = 0;
			}
		}

		b.push_back({c - y, k});

		int res = 1;
		for (pair<int, int> p : b) {
			// print(p.first, p.second);
			range(i, 1, p.second + 1) {
				res = (res * (p.first + i)) % MOD;
				res = modDiv(res, i);
			}
		}

		print(res);
	}
}
