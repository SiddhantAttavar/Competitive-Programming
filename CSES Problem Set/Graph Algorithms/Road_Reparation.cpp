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

	DSU(int n) {
		a = vector<ll>(n, -1);
	}

	ll get(int x) {
		if (a[x] < 0) {
			return x;
		}
		return get(a[x]);
	}

	bool unite(int x, int y) {
		x = get(x);
		y = get(y);

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

int main() {
	setup();
	
	int n, m;
	input(n);
	input(m);

	vector<pair<int, pair<int, int>>> edges(m);
	for (pair<int, pair<int, int>> &e : edges) {
		input(e.second.first);
		input(e.second.second);
		input(e.first);
	}

	sort(edges.begin(), edges.end());

	DSU dsu(n);

	ll cost = 0;
	for (pair<int, pair<int, int>> e : edges) {
		if (dsu.unite(e.second.first - 1, e.second.second - 1)) {
			cost += e.first;
		}
	}

	int u = dsu.get(0);
	range(i, 1, n) {
		if (dsu.get(i) != u) {
			print("IMPOSSIBLE");
			return 0;
		}
	}

	print(cost);
}