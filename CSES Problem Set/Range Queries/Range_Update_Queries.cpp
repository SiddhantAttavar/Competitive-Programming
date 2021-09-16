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

struct SegTree {
	vector<ll> a;

	SegTree(int n) {
		a = vector<ll>(2 * pow(2, ceil(log2(n))) - 1, 0);
	}

	void update(int l, int r, int x, int s, int e, int curr) {
		if (e < l || s > r) {
			return;
		}

		if (s >= l && e <= r) {
			a[curr] += x;
			return;
		}

		int mid = (s + e) / 2;
		update(l, r, x, s, mid, 2 * curr + 1);
		update(l, r, x, mid + 1, e, 2 * curr + 2);
	}

	ll query(int i, int s, int e, int curr) {
		if (s > i || e < i) {
			return 0;
		}

		if (s == e) {
			return a[curr];
		}

		int mid = (s + e) / 2;
		return a[curr] + query(i, s, mid, 2 * curr + 1) + query(i, mid + 1, e, 2 * curr + 2);
	}
};

int main() {
	setup();
	
	int n, q;
	input(n);
	input(q);

	SegTree segTree(n);
	range(i, 0, n) {
		int a; input(a);
		segTree.update(i, i, a, 0, n - 1, 0);
	}

	while (q--) {
		int op; input(op);
		if (op == 1) {
			int a, b, k;
			input(a);
			input(b);
			input(k);

			segTree.update(a - 1, b - 1, k, 0, n - 1, 0);
		}
		else {
			int k; input(k);
			print(segTree.query(k - 1, 0, n - 1, 0));
		}
	}
}