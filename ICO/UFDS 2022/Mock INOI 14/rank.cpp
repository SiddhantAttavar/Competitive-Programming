// https://codebreaker.xyz/problem/rank
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

int n, m;
vector<vector<int>> graph;
vector<bool> visited, inTopo;
vector<int> topo;

bool dfs(int u) {
	visited[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
	topo.push_back(u);
	return true;
}

int32_t main() {
	setup();
	
	input(n, m);

	graph.resize(n);
	while (m--) {
		string s, x, y, z;
		input(s);
		int i = 0;
		while (i < s.size() and s[i] != '>' and s[i] != ',') {
			x += s[i];
			i++;
		}
		char type = s[i];
		i++;
		while (i < s.size() and s[i] != '>' and s[i] != ',') {
			y += s[i];
			i++;
		}
		i++;
		while (i < s.size() and s[i] != '>' and s[i] != ',') {
			z += s[i];
			i++;
		}
		graph[stoi(x) - 1].push_back(stoi(z) - 1);
		if (type == '>') {
			graph[stoi(x) - 1].push_back(stoi(y) - 1);
		}
		else {
			graph[stoi(y) - 1].push_back(stoi(z) - 1);
		}
	}
	
	visited.resize(n);
	range(i, 0, n) {
		if (!visited[i]) {
			if (!dfs(i)) {
				print(0);
				return 0;
			}
		}
	}
	
	reverse(topo.begin(), topo.end());
	set<int> s;
	for (int u : topo) {
		s.insert(u);
		for (int v : graph[u]) {
			if (s.count(v)) {
				print(0);
				return 0;
			}
		}
	}

	for (int i : topo) {
		cout << i + 1 << ' ';
	}
	cout << '\n';
}
