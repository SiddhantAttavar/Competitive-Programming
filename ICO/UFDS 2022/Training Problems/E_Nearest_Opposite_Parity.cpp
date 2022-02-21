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
	
	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	vector<vector<int>> graph(n);
	range(i, 0, n) {
		if (i - a[i] >= 0) {
			graph[i - a[i]].push_back(i);
		}
		if (i + a[i] < n) {
			graph[i + a[i]].push_back(i);
		}
	}

	vector<int> d(n, -1);
	queue<int> q;
	
	range(u, 0, n) {
		if (a[u] % 2 == 0) {
			for (int v : graph[u]) {
				if (a[v] % 2 == 1) {
					d[v] = 1;
					q.push(v);
				}
			}
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		for (int v : graph[u]) {
			if (a[v] % 2 == 1 and d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	
	range(u, 0, n) {
		if (a[u] % 2 == 1) {
			for (int v : graph[u]) {
				if (a[v] % 2 == 0) {
					d[v] = 1;
					q.push(v);
				}
			}
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		for (int v : graph[u]) {
			if (a[v] % 2 == 0 and d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	
	arrPrint(d);
}
