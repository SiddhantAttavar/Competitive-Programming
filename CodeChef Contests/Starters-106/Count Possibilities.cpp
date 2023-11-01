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

int dfs(int u, vector<vector<int>> &graph, int d, vector<int> &a, vector<int> &b) {
	a[d]++;
	int x = 0;
	for (int v : graph[u]) {
		x += dfs(v, graph, d + 1, a, b);
	}
	b[(int) graph.size() - x - 1]++;
	return x + 1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> graph(n);
		vector<bool> root(n, true);
		range(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			root[v - 1] = false;
		}

		int r = 0;
		range(i, 0, n) {
			if (root[i]) {
				r = i;
				break;
			}
		}
		// print(r);
		// cout.flush();

		vector<int> a(n, 0), b(n, 0);
		dfs(r, graph, 0, a, b);

		// arrPrint(a);
		// arrPrint(b);

		int c = 0;
		range(i, 0, n) {
			c += a[i];
			cout << c << ' ';
			c -= b[i];
		}
		print("");
	}
}
