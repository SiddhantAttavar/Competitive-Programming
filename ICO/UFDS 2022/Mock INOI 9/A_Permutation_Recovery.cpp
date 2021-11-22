#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

bool checkCycle(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &curr, int u) {
	visited[u] = true;
	curr[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			if (checkCycle(graph, visited, curr, v)) {
				return true;
			}
		} 
		else if (curr[v]) {
			return true;
		}
	}
	curr[u] = false;
	return false;
}

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int u, vector<int> &ans) {
	visited[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(graph, visited, v, ans);
		}
	}
	ans.push_back(u);
}


int32_t main() {
	setup();
	int n, q; input(n, q);
	vector<vector<int>> graph(q);
	vector<bool> visited(q, false);
	vector<bool> curr(q, false);
	vector<tuple<int, int, int, int>> queries(q);
	range(i, 0, q) {
		int a, b, c; input(a, b, c);
		queries[i] = {a - 1, b - 1, c - 1, i};
	}

	sort(queries.begin(), queries.end(), [](auto &a, auto &b) {
		return get<1>(a) < get<1>(b);
	});

	

	range(u, 0, q) {
		if (!visited[u]) {
			if (checkCycle(graph, visited, curr, u)) {
				print(-1);
				return 0;
			}
		}
	}
	
	vector<int> ans;
	visited = vector<bool>(q, false);
	range(u, 0, q) {
		if (!visited[u]) {
			dfs(graph, visited, u, ans);
		}
	}
	reverse(ans.begin(), ans.end());

	vector<int> res(n, -1);
	int c = 1;
	for (int i : ans) {
		if (res[get<2>(queries[i])] == -1) {
			res[get<2>(queries[i])] = c;
			c++;
		}
	}
	range(i, 0, n) {
		if (res[i] == -1) {
			res[i] = c;
			c++;
		}
	}
	arrPrint(res);
}
