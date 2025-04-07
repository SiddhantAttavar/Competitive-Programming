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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		vector<int> x(k);
		arrput(x);

		vector<vector<int>> graph(n);
		set<pair<int, int>> s;
		rep(i, 0, m) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
			s.insert({u, v});
			s.insert({v, u});
		}

		vector<pair<int, int>> res;
		if (x[0] != 1) {
			res.push_back({1, x[0]});
		}
		rep(i, 1, k) {
			res.push_back({x[i - 1], x[i]});
		}

		for (pair<int, int> p :res) {
			graph[p.first - 1].push_back(p.second - 1);
			graph[p.second - 1].push_back(p.first - 1);
		}

		queue<int> q;
		q.push(0);
		vector<int> d(n, -1);
		d[0] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : graph[u]) {
				if (d[v] == -1) {
					d[v] = d[u] + 1;
					q.push(v);
				}
			}
		}

		bool flag = true;
		rep(i, 0, k) {
			if (d[x[i] - 1] < (i + (x[0] != 1))) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			print(-1);
			continue;
		}

		print(res.size());
		for (pair<int, int> p :res) {
			print(p.first, p.second);
		}
	}
}
