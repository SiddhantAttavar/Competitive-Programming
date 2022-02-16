// https://codebreaker.xyz/problem/subgraphs
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
	vector<int> a;

	DSU(int n) {
		a.resize(n, -1);
	}

	int find(int x) {
		if (a[x] < 0) {
			return x;
		}
		return a[x] = find(a[x]);
	}

	bool unite(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) {
			return false;
		}

		if (a[x] > a[y]) {
			swap(x, y);
		}

		a[x] += a[y];
		a[y] = x;

		return true;
	}
};

int32_t main() {
	setup();
	int n, m;
	input(n, m);
	DSU dsu(n);
	int res = n;
	while (m--) {
		int u, v;
		input(u, v);

		res -= dsu.unite(u, v);
	}
	print(res);
}
