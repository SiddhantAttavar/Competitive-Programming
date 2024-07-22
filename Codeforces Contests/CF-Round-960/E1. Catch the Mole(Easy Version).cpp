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

bool query(int u) {
	print('?', u + 1);
	cout.flush();
	bool res;
	input(res);
	return res;
}

void dfs(int u, vector<set<int>> &graph, vector<int> &d, vector<int> &s, vector<int> &l) {
	for (int v : graph[u]) {
		// print(u, v);
		// cout.flush();
		d[v] = d[u] + 1;
		dfs(v, graph, d, s, l);
		s[u] += s[v];
		l[u] += l[v];
	}
	l[u] += s[u] == 1;
}

void dfs2(int u, vector<set<int>> &graph, vector<int> &p) {
	for (int v : graph[u]) {
		graph[v].erase(u);
		p[v] = u;
		dfs2(v, graph, p);
	}
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<set<int>> graph(n);
		range(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].insert(v - 1);
			graph[v - 1].insert(u - 1);
		}

		if (n == 1) {
			print('!', 1);
			cout.flush();
			continue;
		}

		vector<int> p(n, -1);
		dfs2(0, graph, p);

		int u = 0;
		int x = n;
		int y = 0;
		while (true) {
			vector<int> s(n, 1), d(n, -1), l(n, 0);
			d[u] = 0;
			dfs(u, graph, d, s, l);

			// arrPrint(d);
			// arrPrint(s);
			// arrPrint(l);
			// cout.flush();

			if (s[u] == 1) {
				break;
			}

			int v = -1;
			range(i, 0, n) {
				if (d[i] == -1 or u == i) {
					continue;
				}
				int y = (s[u] - s[i]) - (l[u] - l[i]) - s[i];
				if (y < 0) {
					continue;
				}

				if (v == -1) {
					v = i;
					continue;
				}

				int x = (s[u] - s[v]) - (l[u] - l[v]) - s[v];
				if (y <= x) {
					v = i;
				}
			}
			assert(v != -1);

			assert(y < 300);
			y++;
			if (query(v)) {
				u = v;
				continue;
			}

			range(i, 0, n) {
				if (d[i] != -1 and s[i] == 1) {
					graph[p[i]].erase(i);
				}
			}

			if (graph[p[v]].count(v)) {
				graph[p[v]].erase(v);
			}
		}

		print('!', u + 1);
		cout.flush();
	}
}
