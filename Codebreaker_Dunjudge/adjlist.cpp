// https://codebreaker.xyz/problem/adjlist
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

int32_t main() {
	setup();
	int n, e;
	input(n, e);
	vector<vector<int>> graph(n);
	while (e--) {
		int a, b;
		input(a, b);
		assert(0 < a and a <= n);
		assert(0 < b and b <= n);
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}
	range(i, 0, n) {
		range(j, 0, graph[i].size() - 1) {
			cout << graph[i][j] + 1 << ' ';
		}
		if (!graph[i].empty()) {
			cout << graph[i].back() + 1 << endl;
		}
	}
}
