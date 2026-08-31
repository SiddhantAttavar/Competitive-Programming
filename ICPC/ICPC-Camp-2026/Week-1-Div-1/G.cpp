#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e9, M = 5e5 * 40;
ll seg[M] = {}, lazy[M] = {};
pair<int32_t, int32_t> tree[M] = {};
int T = 0;

void push(int c, int l, int r) {
	seg[c] += lazy[c] * (r - l + 1);
	if (l == r) {
		lazy[c] = 0;
		return;
	}

	if (tree[c].first == -1) {
		tree[c].first = ++T;
		assert(T < M);
		tree[T] = {-1, -1};
		seg[T] = 0;
		lazy[T] = 0;
	}
	if (tree[c].second == -1) {
	tree[c].second = ++T;
		assert(T < M);
		tree[T] = {-1, -1};
		seg[T] = 0;
		lazy[T] = 0;
	}

	lazy[tree[c].first] += lazy[c];
	lazy[tree[c].second] += lazy[c];
	lazy[c] = 0;
}

void upd(int l, int r, int c, int s, int e, int a) {
	if (l > e or r < s) {
		return;
	}
	if (s <= l and r <= e) {
		lazy[c] += a;
		return;
	}

	push(c, l, r);
	int m = (l + r) / 2;
	if (s <= m) {
		upd(l, m, tree[c].first, s, e, a);
	}
	if (e > m) {
		upd(m + 1, r, tree[c].second, s, e, a);
	}

	seg[c] = 0;
	if (tree[c].first != -1) {
		seg[c] += seg[tree[c].first] + lazy[tree[c].first] * (m - l + 1);
	}
	if (tree[c].second != -1) {
		seg[c] += seg[tree[c].second] + lazy[tree[c].second] * (r - m);
	}
}

ll query(int l, int r, int c, int s, int e) {
	if (l > e or r < s) {
		return 0;
	}

	push(c, l, r);
	if (s <= l and r <= e) {
		return seg[c];
	}

	int m = (l + r) / 2;
	return query(l, m, tree[c].first, s, e) + query(m + 1, r, tree[c].second, s, e);
}

void solve() {
    int q;
	cin >> q;

	vector<pii> a;
	ll z = 0;
	while (q--) {
		int o;
		cin >> o;

		if (o == 1) {
			int x, b;
			cin >> x >> b;
			a.push_back({x, b});

			z += max(0ll, b - x - 1);
			upd(0, N, 0, x - b + 1, x, 1);
			upd(0, N, 0, x + 1, x + b, -1);
		}
		else if (o == 2) {
			int i;
			cin >> i;
			auto [x, b] = a[i - 1];

			z -= max(0ll, b - x - 1);
			upd(0, N, 0, x - b + 1, x, -1);
			upd(0, N, 0, x + 1, x + b, 1);
		}
		else {
			int y;
			cin >> y;

			cout << z + query(0, N, 0, 0, y) << endl;
		}
	}
}

signed main() {
	tree[0] = {-1, -1};
	seg[0] = 0;
	lazy[0] = 0;
	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
