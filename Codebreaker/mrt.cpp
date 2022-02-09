// https://codebreaker.xyz/problem/mrt
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

int32_t main() {
	setup();
	
	int n, m, q;
	input(n, m, q);
	vector<vector<int>> graph(n, vector<int>(n, 1e18));

	range(u, 0, n) {
		graph[u][u] = 0;
	}
	while (m--) {
		int u, v, w;
		input(u, v, w);
		graph[u][v] = w;
		graph[v][u] = w;
	}

	range(k, 0, n) {
		range(i, 0, n) {
			range(j, 0, n) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[j][k]);
			}
		}
	}

	while (q--) {
		int u, v;
		input(u, v);
		if (graph[u][v] < 1e18) {
			print(graph[u][v]);
		}
		else {
			print(-1);
		}
	}
}
