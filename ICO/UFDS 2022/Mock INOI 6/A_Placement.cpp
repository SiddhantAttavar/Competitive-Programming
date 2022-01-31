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

int n;
int k;
int sumDist;
vector<vector<int>> graph;
set<int> s;
vector<int> numSpecial;
vector<int> numChild;
vector<int> dp;

int dfs1(int u, int p, int d) {
	numSpecial[u] = s.count(u);
	int res = numSpecial[u] * d;
	for (int v : graph[u]) {
		if (v != p) {
			res += dfs1(v, u, d + 1);
			numChild[u] += numChild[v];
			numSpecial[u] += numSpecial[v];
		}
	}
	return res;
}

void dfs2(int u, int p) {
	for (int v : graph[u]) {
		if (v != p) {
			dp[v] = dp[u] + numSpecial[0] - 2 * numSpecial[v];
			dfs2(v, u);
		}
	}
}

int32_t main() {
	setup();
	
	input(n);
	graph.resize(n);
	range(i, 0, n - 1) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	input(k);
	while (k--) {
		int u;
		input(u);
		s.insert(u - 1);
	}

	numSpecial.resize(n);
	numChild.resize(n);
	sumDist += dfs1(0, -1, 0);

	dp.resize(n);
	dp[0] = sumDist;
	dfs2(0, -1);
	
	int res = LLONG_MAX, resCount = 0;
	for (int x : dp) {
		if (res > x) {
			res = x;
			resCount = 1;
		}
		else if (res == x) {
			resCount++;
		}
	}
	print(resCount, res);
}
