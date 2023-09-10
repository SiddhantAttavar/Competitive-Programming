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

struct DSU {
	vector<int> a;

	DSU(int n) {
		a.resize(n, -1);
	}

	int get(int x) {
		if (a[x] < 0) {
			return x;
		}
		return a[x] = get(a[x]);
	}

	bool unite(int x, int y) {
		x = get(x);
		y = get(y);

		if (x == y) {
			return false;
		}

		if (a[y] < a[x]) {
			swap(x, y);
		}

		a[x] += a[y];
		a[y] = x;
		return true;
	}
};

int32_t main() {
	setup();

	int m, n;
	input(m, n);

	vector<vector<int>> v(n);
	range(i, 0, m) {
		int x;
		input(x);
		vector<int> a(x);
		arrPut(a);

		for (int j : a) {
			v[j - 1].push_back(i);
		}
	}

	// range(i, 0, n) {
	// 	arrPrint(v[i]);
	// }

	int res = 0;
	DSU d(m);
	range(i, 0, n) {
		if (d.unite(v[i][0], v[i][1])) {
			res++;
		}
	}

	print(res);
}
