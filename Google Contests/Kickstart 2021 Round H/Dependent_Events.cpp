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

int n, q;
vector<vector<int>> graph;
vector<int> a, b, p, d;

int32_t main() {
	setup();
	int tc; input(tc);
	range(t, 1, tc + 1) {
		input(n, q);
		
		p.resize(n);
		p[0] = -1;
		a.resize(n);
		b.resize(n);
		d.resize(n);
		graph.clear();
		graph.resize(n);
		input(a[0]);
		b[0] = a[0];

		range(i, 1, n) {
			input(p[i], a[i], b[i]);
			p[i]--;
			graph[p[i]].push_back(i);
		}

		while (q--) {
			int u, v;
		}
	}
}