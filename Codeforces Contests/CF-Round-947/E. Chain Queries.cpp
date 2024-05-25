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

void dfs(int u, vector<vector<int>> &graph, vector<int> &p) {
	for (int v : graph[u]) {
		if (v != p[u]) {
			p[v] = u;
			dfs(v, graph, p);
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vector<int> c(n);
		arrPut(c);

		vector<vector<int>> graph(n);
		range(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<int> p(n, -1);
		dfs(0, graph, p);

		vector<int> x(n, 0);
		range(i, 1, n) {
			if (c[i]) {
				x[p[i]]++;
			}
		}

		int k = 0;
		set<int> a, b;
		range(i, 0, n) {
			if (!c[i]) {
				continue;
			}

			k++;
			if (x[i] == 1) {
				a.insert(i);
			}
			else if (x[i] == 2) {
				b.insert(i);
			}
		}

		while (q--) {
			int u;
			input(u);
			u--;

			if (c[u]) {
				if (u) {
					x[p[u]]--;
					if (c[p[u]]) {
						if (x[p[u]] == 2) {
							b.insert(p[u]);
						}
						else if (x[p[u]] == 1) {
							b.erase(p[u]);
							a.insert(p[u]);
						}
						else if (x[p[u]] == 0) {
							a.erase(p[u]);
						}
					}
				}

				if (a.count(u)) {
					a.erase(u);
				}
				else if (b.count(u)) {
					b.erase(u);
				}
				c[u] = false;
				k--;
			}
			else {
				if (u) {
					x[p[u]]++;
					if (c[p[u]]) {
						if (x[p[u]] == 1) {
							a.insert(p[u]);
						}
						else if (x[p[u]] == 2) {
							a.erase(p[u]);
							b.insert(p[u]);
						}
						else if (x[p[u]] == 3) {
							b.erase(p[u]);
						}
					}
				}

				if (a.count(u)) {
					a.erase(u);
				}
				else if (b.count(u)) {
					b.erase(u);
				}
				if (x[u] == 1) {
					a.insert(u);
				}
				else if (x[u] == 2) {
					b.insert(u);
				}
				c[u] = true;
				k++;
			}

			if (b.size() == 1 and a.size() == k - 3 and (*b.begin() == 0 or !c[p[*b.begin()]])) {
				print("Yes");
			}
			else if (b.size() == 0 and a.size() == k - 1) {
				print("Yes");
			}
			else {
				print("No");
			}
		}
	}
}
