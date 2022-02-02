// https://codebreaker.xyz/problem/yabbitmeetup
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
#define int long long

int n, y;
vector<int> p, t;
vector<int> m;
vector<vector<pair<int, int>>> graph;
vector<int> numYabbit;
vector<int> sumDistYabbit;
vector<int> minDistYabbit;
vector<int> minMessiness;
vector<int> res;

void dfs(int u) {
	for (pair<int, int> e : graph[u]) {
		int v, w;
		tie(v, w) = e;
		if (v != p[u] - 1) {
			dfs(v);
			sumDistYabbit[u] += sumDistYabbit[v] + w * numYabbit[v];
			numYabbit[u] += numYabbit[v];
		}
	}

	if (u >= n) {
		minDistYabbit[u] = 0;
		minMessiness[u] = m[u - n];
		numYabbit[u] = 1;
	}
	else {
		queue<pair<int, int>> q;
		q.push({u, 0});
		while (!q.empty()) {
			int i, d;
			tie(i, d) = q.front();
			q.pop();

			for (pair<int, int> e : graph[i]) {
				int v, w;
				tie(v, w) = e;
				if (v != p[u] - 1) {
					q.push({v, d + w});
				}
			}

			if (i >= n) {
				res[u] = min(res[u], sumDistYabbit[u] + d * numYabbit[u] + m[i - n]);
			}
		}
	}
}

int32_t main() {
	setup();
	
	input(n, y);
	p.resize(n + y);
	t.resize(n + y);
	range(i, 0, n + y) {
		input(p[i], t[i]);
	}

	m.resize(y);
	arrPut(m);

	graph.resize(n + y);
	range(i, 1, n + y) {
		graph[p[i] - 1].push_back({i, t[i]});
	}

	numYabbit.resize(n + y);
	sumDistYabbit.resize(n + y);
	minDistYabbit.resize(n + y, LLONG_MAX);
	minMessiness.resize(n + y);
	res.resize(n, LLONG_MAX);
	dfs(0);

	arrPrint(res);
}
