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

struct DSU {
	vector<int> p, a, x;
	int res = 0;

	DSU(int n) {
		p.resize(n);
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
		a.resize(n, 1);
		x.resize(n, 0);
	}

	int find(int x) {
		return p[x] == x ? x : p[x] = find(p[x]);
	}

	bool unite(int l, int r) {
		l = find(l);
		r = find(r);
		if (l == r) {
			x[l]++;
			res--;
			return false;
		}
		if (a[l] < a[r]) {
			swap(l, r);
		}

		res -= a[l] * (a[l] - 1) / 2 - x[l];
		res -= a[r] * (a[r] - 1) / 2 - x[r];

		p[r] = l;
		a[l] += a[r];
		x[l] += x[r] + 1;
		
		res += a[l] * (a[l] - 1) / 2 - x[l];

		return true;
	}
};

int32_t main() {
	setup();
	int n, m; input(n, m);
	vector<set<int>> graph(n);
	int res = 0;
	DSU dsu(n);
	while (m--) {
		int u, v; input(u, v);
		u--; v--;
		
		if (graph[u].find(v) != graph[u].end()) {
			print(res);
			continue;
		}

		graph[u].insert(v);
		graph[v].insert(u);
		
		dsu.unite(u, v);

		res = dsu.res;
		print(res);
	}
}
