#include "game.h"
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, k;
vector<vector<int>> graph, revGraph;
vector<vector<bool>> reach, revReach;

void init(int N, int K) {
	n = N;
	k = K;

	graph.resize(n);
	revGraph.resize(n);
	reach.resize(k, vector<bool>(n, false));
	revReach.resize(k, vector<bool>(n, false));

	range(i, 0, k - 1) {
		graph[i].push_back(i + 1);
		revGraph[i + 1].push_back(i);
	}

	range(i, 0, k) {
		range(j, i + 1, k) {
			reach[i][j] = true;
		}
		range(j, 0, i) {
			revReach[i][j] = true;
		}
	}
}

void dfs(int u, int i, vector<vector<int>> &graph, vector<vector<bool>> &reach) {
	// print(u);
	reach[i][u] = true;
	for (int v : graph[u]) {
		if (!reach[i][v]) {
			dfs(v, i, graph, reach);
		}
	}
}

int add_teleporter(int u, int v) {
	graph[u].push_back(v);
	revGraph[v].push_back(u);

	range(i, 0, k) {
		if (reach[i][u] or i == u) {
			dfs(v, i, graph, reach);
		}
		if (revReach[i][v] or i == v) {
			dfs(u, i, revGraph, revReach);
		}
		
		// arrPrint(reach[i]);
		// arrPrint(revReach[i]);
		
		if (reach[i][i]) {
			return true;
		}
	}
	
	return false;
}
