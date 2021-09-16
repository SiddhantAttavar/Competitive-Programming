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
typedef long long ll;

vector<vector<int>> graph;
vector<int> visited;
vector<vector<pair<int, int>>> cycles;
stack<int> s;

void addCycle(int u) {
	stack<int> s2;
	s2.push(s.top());
	s.pop();
	while (s2.top() != u) {
		s2.push(s.top());
		s.pop();
	}
	cycles.push_back({});
	int curr = u;
	s.push(s2.top());
	s2.pop();
	while (!s2.empty()) {
		int next = s2.top();
		s2.pop();
		s.push(next);
		cycles.back().push_back({curr, next});
		curr = next;
	}
	cycles.back().push_back({curr, u});
}

void dfs(int u) {
	visited[u] = 0;
	s.push(u);
	for (int v : graph[u]) {
		if (visited[v] == 0) {
			addCycle(v);
		}
		else if (visited[v] == -1) {
			dfs(v);
		}
	}
	visited[u] = 1;
	s.pop();
}

int main() {
	setup();
	
	int n, m;
	input(n, m);

	graph.resize(n);
	visited = vector<int>(n, -1);

	range(i, 0, m) {
		int u, v; input(u, v);
		graph[u - 1].push_back(v - 1);
	}

	range(u, 0, n) {
		if (visited[u] == -1) {
			s = stack<int>();
			s.push(u);
			dfs(u);
		}
	}

	for (vector<pair<int, int>> cycle : cycles) {
		for (pair<int, int> edge : cycle) {
			cout << edge.first << " -> " << edge.second << ' ';
		}
		cout << endl;
	}
}