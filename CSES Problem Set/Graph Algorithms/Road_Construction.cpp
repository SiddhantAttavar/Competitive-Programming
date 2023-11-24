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
	int l, n;
	
	DSU(int x) {
		a.resize(x, -1);
		l = 1;
		n = x;
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
		this->l = max(this->l, -a[y]);
		this->n--;
		return true;
	}
};

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	DSU d(n);
	range(i, 0, m) {
		int u, v;
		input(u, v);

		d.unite(u - 1, v - 1);
		print(d.n, d.l);
	}
}
