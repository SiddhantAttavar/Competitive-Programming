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
typedef long long ll;

struct DSU {
	vector<int> e;
	int groups;

	void init(int n) {
		e.resize(n);
		fill(e.begin(), e.end(), -1);
		groups = n;
	}

	int get(int x) {
		if (e[x] < 0) {
			return x;
		}
		return e[x] = get(e[x]);
	}

	void unite(int x, int y) {
		x = get(x);
		y = get(y);

		if (x == y) {
			return;
		}

		if (e[x] > e[y]) {
			swap(x, y);
		}
		e[x] += e[y];
		e[y] = x;
		groups--;
	}
};

vector<int> a, b;
DSU dsu;

bool intersects(int i, int j) {
	//The horizontal line is from (0, i + 1) to (a[i], i + 1)
	//The vertical line is from (j + 1, 0) to (j + 1, b[j])
	if (a[i] < j + 1) {
		return false;
	}
	return i + 1 <= b[j];
}

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		a.resize(n);
		b.resize(m);

		arrPut(a);
		arrPut(b);

		dsu.init(n + m);

		range(i, 0, n) {
			range(j, 0, m) {
				if (intersects(i, j)) {
					dsu.unite(i, j + n);
				}
			}
		}

		print(dsu.groups);
	}
}