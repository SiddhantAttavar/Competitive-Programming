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
	ll id;

	ll (*combine) (ll, ll);

	SegTree(int n, int i, ll func(ll, ll)) {
		id = i;
		combine = func;
		a = vector<ll>(2 * pow(2, ceil(log2(n))) - 1, id);
	}

	ll query(int l, int r, int s, int e, int curr) {
		if (l > e || r < s) {
			return id;
		}

		if (l <= s && r >= e) {
			return a[curr];
		}

		int mid = (s + e) / 2;
		return combine(
			query(l, r, s, mid, 2 * curr + 1),
			query(l, r, mid + 1, e, 2 * curr + 2)
		);
	}

	void update(int i, int x, int s, int e, int curr) {
		if (s > i || e < i) {
			return;
		}

		if (s == e) {
			a[curr] = x;
			return;
		}

		int mid = (s + e) / 2;

		update(i, x, s, mid, 2 * curr + 1);
		update(i, x, mid + 1, e, 2 * curr + 2);

		a[curr] = combine(a[2 * curr + 1], a[2 * curr + 2]);
	}
};

int main() {
	setup();
	
	int n, q;
	input(n);
	input(q);

	SegTree segTree(n, 0, [](ll a, ll b) {
		return a ^ b;
	});

	range(i, 0, n) {
		int x; input(x);
		segTree.update(i, x, 0, n - 1, 0);
	}

	while (q--) {
		int a, b;
		input(a);
		input(b);

		print(segTree.query(a - 1, b - 1, 0, n - 1, 0));
	}
}