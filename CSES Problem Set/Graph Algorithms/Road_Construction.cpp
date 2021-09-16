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

	int get(int x) {
		if (a[x] < 0) {
			return x;
		}
		return a[x] = get(a[x]);
	}

	ll unite(int x, int y) {
		x = get(x);
		y = get(y);

		if (x == y) {
			return -1;
		}

		if (a[x] < a[y]) {
			swap(x, y);
		}

		a[x] += a[y];
		a[y] = x;

		return -a[x];
	}
};

int main() {
	setup();
	
	int n, m;
	input(n);
	input(m);

	DSU dsu(n);
	ll currMax = 1;

	range(i, 0, m) {
		int a, b;
		input(a);
		input(b);

		ll x = dsu.unite(a - 1, b - 1);
		if (x != -1) {
			n--;
			currMax = max(currMax, x);
		}

		print(n << " " << currMax);
	}
}