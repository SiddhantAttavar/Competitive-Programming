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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		int u = 0;
		string s;
		input(s);
		range(i, 0, n) {
			u = 2 * u + (s[i] - '0');
		}

		vector<int> d(m);
		vector<pair<int, int>> e(m, {0, 0});
		range(i, 0, m) {
			input(d[i]);

			string s, t;
			input(s, t);
			range(j, 0, n) {
				e[i].first = 2 * e[i].first + (s[j] - '0');
				e[i].second = 2 * e[i].second + (t[j] - '0');
			}
		}

		vector<vector<pair<int, int>>> graph(1 << n);
		range(i, 0, 1 << n) {
			range(j, 0, m) {
				graph[i].push_back({(i & ~e[j].first) | e[j].second, d[j]});
			}
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int> x(1 << n, 1e9);
		x[u] = 0;
		pq.push({0, u});

		while (!pq.empty()) {
			int y, u;
			tie(y, u) = pq.top();
			pq.pop();

			for (pair<int, int> p : graph[u]) {
				int v, w;
				tie(v, w) = p;
				if (x[v] > y + w) {
					x[v] = y + w;
					pq.push({x[v], v});
				}
			}
		}

		if (x[0] == 1e9) {
			print(-1);
		}
		else {
			print(x[0]);
		}
	}
}
