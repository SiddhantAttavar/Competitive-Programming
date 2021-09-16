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

struct SegmentTree {
	vector<ll> segTree = vector<ll>((int) 1e6, 1e15);

	SegmentTree(vector<ll> &a) {
		range(i, 0, a.size()) {
			update(i, a[i], 0, a.size() - 1, 1);
		}
	}

	void update(int i, ll x, int l, int r, int curr) {
		if (l > i || r < i) {
			return;
		}

		if (l == r) {
			segTree[curr] = x;
			return;
		}

		int mid = (l + r) / 2;
		update(i, x, l, mid, 2 * curr);
		update(i, x, mid + 1, r, 2 * curr + 1);
		segTree[curr] = min(segTree[2 * curr], segTree[2 * curr + 1]);
	}

	ll query(int l, int r, int s, int e, int curr) {
		if (l > e || r < s) {
			return 1e10;
		}

		if (l <= s && r >= e) {
			return segTree[curr];
		}

		int mid = (s + e) / 2;
		return min(query(l, r, s, mid, 2 * curr), query(l, r, mid + 1, e, 2 * curr + 1));
	}
};

int main() {
	setup();
	
	int n, q;
	input(n);
	input(q);

	vector<ll> x(n); arrPut(x);
	SegmentTree segTree(x);

	while (q--) {
		int a, b;
		input(a);
		input(b);
		print(segTree.query(a - 1, b - 1, 0, n - 1, 1));
	}
}