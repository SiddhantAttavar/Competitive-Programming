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

const int MOD = (int) 1e9 + 7;

int dfs(int u, int p, int x, vector<vector<int>> &graph, vector<int> &size) {
	int res = 0;
	for (int v : graph[u]) {
		if (v != p) {
			res += dfs(v, u, x, graph, size) + (size[v] % x == 0);
			size[u] += size[v];
		}
	}
	return res;
}

int mod_div(int a, int b) {
	int x = 1, y = MOD - 2;
	while (y) {
		if (y % 2 == 1) {
			x = (x * b) % MOD;
		}

		b = (b * b) % MOD;
		y /= 2;
	}
	return (a * x) % MOD;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, x;
		input(n, x);
		
		vector<int> a(n);
		arrPut(a);

		vector<vector<int>> graph(n);
		set<int> root;
		range(i, 0, n) {
			root.insert(i);
		}
		range(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			root.erase(v - 1);
		}

		vector<int> size(a.begin(), a.end());
		int l = dfs(*root.begin(), -1, x, graph, size);


		vector<int> res(n, 0);
		if (size[*root.begin()] % x != 0) {
			arrPrint(res);
			continue;
		}

		res[0] = 1;
		range(i, 1, l + 1) {
			res[i] = mod_div((res[i - 1] * (l - i + 1)) % MOD, i);
		}
		arrPrint(res);
	}
}
