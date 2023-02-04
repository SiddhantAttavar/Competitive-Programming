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

int n, m, p;
vector<vector<int>> graph;
vector<int> c;

void dfs(int u, int x, pair<int, int> e) {
	c[u] = x;
	for (int v : graph[u]) {
		if (c[v] == -1 and (e != make_pair(min(u, v), max(u, v)))) {
			dfs(v, x, e);
		}
	}
}

int32_t main() {
	setup();

	input(n, m, p);

	graph.clear();
	graph.resize(n);
	vector<pair<int, int>> e(m);
	range(i, 0, m) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
		e[i] = {u - 1, v - 1};
		if (e[i].first > e[i].second) {
			swap(e[i].first, e[i].second);
		}
	}

	if (n == 2) {
		print(1);
		print("01");
		return 0;
	}

	c.resize(n);

	print(n);
	range(j, 0, n) {
		cout << !(j == 0);
	}
	cout << endl;
	range(i, 1, n) {
		range(j, 0, n) {
			cout << (j == i);
		}
		cout << endl;
	}
}

