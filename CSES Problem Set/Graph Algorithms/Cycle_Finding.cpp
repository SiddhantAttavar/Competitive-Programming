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

void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis);
		}
	}
}

bool cycle(int u, vector<vector<int>> &graph, vector<bool> &in_stack, set<pair<int, int>> &s, vector<int> &p) {
	in_stack[u] = true;

	for (int v : graph[u]) {
		if (p[v] == -1 and s.count({u, v})) {
			p[v] = u;
			if (cycle(v, graph, in_stack, s, p)) {
				return true;
			}
		}
		else if (s.count({u, v}) and in_stack[v]) {
			vector<int> res = {v + 1, u + 1};
			while (u != v) {
				u = p[u];
				res.push_back(u + 1);
			}
			reverse(res.begin(), res.end());
			arrPrint(res);
			return true;
		}
	}

	in_stack[u] = false;
	return false;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<int>> graph(n);
	vector<pair<pair<int, int>, int>> e;
	range(i, 0, m) {
		int u, v, w;
		input(u, v, w);

		graph[u - 1].push_back(v - 1);
		e.push_back({{u - 1, v - 1}, w});
	}

	vector<bool> vis(n, false);
	vector<int> d(n, 1e18);
	range(i, 0, n) {
		if (!vis[i]) {
			d[i] = 0;
			dfs(i, graph, vis);
		}
	}

	// arrPrint(d);
	range(i, 0, n - 1) {
		for (pair<pair<int, int>, int> p : e) {
			d[p.first.second] = min(d[p.first.second], d[p.first.first] + p.second);
		}
	}
	// arrPrint(d);

	set<pair<int, int>> s;
	bool flag = false;
	range(i, 0, n) {
		for (pair<pair<int, int>, int> p : e) {
			// print(p.first.first, p.first.second, p.second);
			if ((d[p.first.first] + p.second) < d[p.first.second]) {
				d[p.first.second] = d[p.first.first] + p.second;
				s.insert(p.first);
				flag = true;
			}
		}
	}

	if (!flag) {
		print("NO");
		return 0;
	}

	print("YES");

	// for (pair<int, int> p : s) {
	// 	print(p.first, p.second);
	// }

	vector<int> p(n, -1);
	vector<bool> in_stack(n, false);
	range(i, 0, n) {
		if (p[i] == -1) {
			p[i] = n;
			if (cycle(i, graph, in_stack, s, p)) {
				return 0;
			}
		}
	}
}
