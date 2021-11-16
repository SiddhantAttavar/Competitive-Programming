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

int n, k;
int totalSum;
vector<vector<int>> graph;
vector<bool> a;
vector<int> numChildren;
vector<int> res;

int dfs1(int u, int p) {
	int res = 0;
	if (a[u]) {
		numChildren[u] = 1;
	}
	for (int v : graph[u]) {
		if (v != p) {
			res += dfs1(v, u);
			numChildren[u] += numChildren[v];
			res += numChildren[v];
		}
	}
	return res;
}

void dfs2(int u, int p) {
	for (int v : graph[u]) {
		if (v != p) {
			//print(u, v, numChildren[v]);
			res[v] = res[u] - numChildren[v] + (k - numChildren[v]);
			dfs2(v, u);
		}
	}
}

int32_t main() {
	setup();
	input(n);
	graph = vector<vector<int>>(n);
	a = vector<bool>(n, false);
	numChildren = vector<int>(n, 0);
	res = vector<int>(n, 0);

	range(i, 0, n - 1) {
		int u, v; input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	input(k);
	range(i, 0, k) {
		int x; input(x);
		a[x - 1] = true;
	}

	totalSum = dfs1(0, -1);
	res[0] = totalSum;
	dfs2(0, -1);
	//arrPrint(numChildren);
	//arrPrint(res);
	
	int minSumDist = LONG_LONG_MAX;
	int minSumDistCount = 0;
	for (int i : res) {
		if (i < minSumDist) {
			minSumDist = i;
			minSumDistCount = 1;
		} else if (i == minSumDist) {
			minSumDistCount++;
		}
	}
	print(minSumDistCount, minSumDist);
}