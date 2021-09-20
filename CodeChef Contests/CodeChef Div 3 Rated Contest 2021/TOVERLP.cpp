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
	unordered_map<int, ll> a, b;

	void update(int l, int r, int s, int e, int curr) {
		if (s > e) {
			return;
		}

		if (r < s || e < l) {
			return;
		}		

		if (l <= s && e <= r) {
			b[curr]++;
			a[curr] += e - s + 1;
			return;
		}

		int mid = (s + e) / 2;
		update(l, r, s, mid, 2 * curr + 1);
		update(l, r, mid + 1, e, 2 * curr + 2);
		a[curr] = a[2 * curr] + a[2 * curr + 1];
	}

	ll query(int l, int r, int s, int e, int curr) {
		if (s > e) {
			return 0;
		}

		if (r < s || e < l) {
			return 0;
		}

		if (l <= s && e <= r) {
			return a[curr];
		}

		int res;
		if (l <= s) {
			res = b[curr] * (e - l + 1);
		}
		else {
			res = b[curr] * (r - s + 1);
		}

		int mid = (s + e) / 2;
		return res + query(l, r, s, mid, 2 * curr + 1) + query(l, r, mid + 1, e, 2 * curr + 2);
	}
};

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, m;
		input(n);
		input(m);

		SegTree segTree;
		range(i, 0, n) {
			int l, r;
			input(l);
			input(r);
			segTree.update(l, r - 1, 1, 1e8, 0);
		}

		ll res = 0;
		range(i, 0, m) {
			int l, r;
			input(l);
			input(r);
			res += segTree.query(l, r - 1, 1, 1e8, 0);
		}

		print(res);
	}
}