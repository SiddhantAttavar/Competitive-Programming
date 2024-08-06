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

bool dfs(int u, vector<vector<int>> &graph, vector<int> &c) {
	for (int v : graph[u]) {
		if (c[v] == 0) {
			c[v] = -c[u];
			if (!dfs(v, graph, c)) {
				return false;
			}
		}
		else if (c[u] == c[v]) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<int>> graph(n);
		range(i, 0, m) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<int> c(n, 0);
		c[0] = 1;
		if (dfs(0, graph, c)) {
			vector<int> x, y;
			range(i, 0, n) {
				if (c[i] == 1) {
					x.push_back(i + 1);
				}
				else {
					y.push_back(i + 1);
				}
			}

			print("Bob");
			cout.flush();
			range(i, 0, n) {
				int a, b;
				input(a, b);

				if ((a == 1 or b == 1) and x.size()) {
					print(x.back(), 1);
					cout.flush();
					x.pop_back();
				}
				else if ((a == 2 or b == 2) and y.size()) {
					print(y.back(), 2);
					cout.flush();
					y.pop_back();
				}
				else if (x.size()) {
					print(x.back(), 3);
					cout.flush();
					x.pop_back();
				}
				else {
					print(y.back(), 3);
					cout.flush();
					y.pop_back();
				}
			}
		}
		else {
			print("Alice");
			cout.flush();
			range(i, 0, n) {
				print(1, 2);
				cout.flush();
				int u, x;
				input(u, x);
			}
		}
	}
}
