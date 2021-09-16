#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

struct DSU {
	vector<ll> a;
	vector<int> p;

	DSU(int n) {
		a.resize(n);
		arrPut(a);
		p.resize(n);
		range(i, 0, n) {
			p[i] = i;
		}
	}

	int get(int x) {
		if (x == p[x]) {
			return x;
		}
		return p[x] = get(p[x]);
	}

	bool unite(int x, int y) {
		x = get(x);
		y = get(y);

		if (x == y) {
			return false;
		}

		if (a[x] < a[y]) {
			a[y] += a[x];
			p[x] = y;
		}
		else if (a[y] < a[x]) {
			a[x] += a[y];
			p[y] = x;
		}

		return true;
	}
};

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n; input(n);

		DSU dsu(n);

		int q; input(q);
		while (q--) {
			int op; input(op);
			if (op == 0) {
				int x, y;
				input(x);
				input(y);

				if (!dsu.unite(x - 1, y - 1)) {
					print("Invalid query!");
				}
			}
			else {
				int x; input(x);
				print(dsu.get(x - 1) + 1);
			}
		}
	}
}