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

void dfs(int u, vector<vector<int>> &graph, vector<int> &disc, vector<int> &low, int &t, stack<int> &s, vector<int> &res, int &c, vector<bool> &in_stack) {
	// print(u);
	// arrPrint(in_stack);
	in_stack[u] = true;
	low[u] = disc[u] = t;
	t++;
	s.push(u);

	for (int v : graph[u]) {
		if (disc[v] == -1) {
			// print(u, v);
			dfs(v, graph, disc, low, t, s, res, c, in_stack);
			low[u] = min(low[u], low[v]);
		}
		else if (in_stack[v]) {
			low[u] = min(low[u], disc[v]);
		}
	}

	if (disc[u] == low[u]) {
		c++;
		while (s.top() != u) {
			res[s.top()] = c;
			in_stack[s.top()] = false;
			s.pop();
		}
		res[u] = c;
		in_stack[u] = false;
		s.pop();
	}
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<int>> graph(n);
	range(i, 0, m) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
	}

	vector<bool> in_stack(n, false);
	vector<int> disc(n, -1), low(n, 1e18), res(n);
	int c = 0, t = 0;
	stack<int> s;
	range(i, 0, n) {
		if (disc[i] == -1) {
			dfs(i, graph, disc, low, t, s, res, c, in_stack);
		}
	}

	// arrPrint(disc);
	// arrPrint(low);

	print(*max_element(res.begin(), res.end()));
	arrPrint(res);
}
