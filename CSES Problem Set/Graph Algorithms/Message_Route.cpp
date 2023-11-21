#include <bits/stdc++.h>
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

	int n, m;
	input(n, m);

	vector<vector<int>> graph(n);
	range(i, 0, m) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> p(n, -1);
	queue<int> q;
	q.push(0);
	p[0] = n;
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (u == n - 1) {
			break;
		}

		for (int v : graph[u]) {
			if (p[v] == -1) {
				p[v] = u;
				q.push(v);
			}
		}
	}

	if (p[n - 1] == -1) {
		print("IMPOSSIBLE");
		return 0;
	}

	vector<int> c;
	c.push_back(n);
	int u = n - 1;
	while (u != 0) {
		u = p[u];
		c.push_back(u + 1);
	}

	print(c.size());
	reverse(c.begin(), c.end());
	arrPrint(c);
}
