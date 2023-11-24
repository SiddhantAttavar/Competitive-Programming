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

		if (a[x] < a[y]) {
			swap(x, y);
		}

		a[y] += a[x];
		a[x] = y;
		return true;
	}
};

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<pair<int, pair<int, int>>> e(m);
	range(i, 0, m) {
		input(e[i].second.first, e[i].second.second, e[i].first);
	}
	sort(e.begin(), e.end());

	int res = 0, x = n;
	DSU d(n);
	for (pair<int, pair<int, int>> p : e) {
		if (d.unite(p.second.first - 1, p.second.second - 1)) {
			res += p.first;
			x--;
		}
	}

	if (x > 1) {
		print("IMPOSSIBLE");
	}
	else {
		print(res);
	}
}
