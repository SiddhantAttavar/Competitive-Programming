#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;

int mpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int mdiv(int a, int b) {
	return a * mpow(b, MOD - 2) % MOD;
}

struct SegTree {
	vector<array<int, 4>> seg;
	int n;
	array<int, 4> ID = {0, -(int) 1e18, -(int) 1e18, -(int) 1e18};
	SegTree(int _n) {
		for (n = 1; n < _n; ) n *= 2;
		seg.resize(2 * n, ID);
	}
	array<int, 4> cmb(array<int, 4> a, array<int, 4> b) {
		int p = min(a[0], b[0]), q = max(a[1], b[1]);
		return {p, q, max(a[2], b[2] - 2 * (p - b[0])), max(a[3], b[3] - 2 * (q - b[1]))};
	}
	void pull(int p) {
		seg[p] = cmb(seg[2 * p], seg[2 * p + 1]);
	}
	void upd(int p, array<int, 4> val) {
		seg[p += n] = val;
		for (p /= 2; p; p /= 2) pull(p);
	}
	array<int, 4> query(int l, int r) {
		array<int, 4> ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) ra = cmb(ra, seg[l++]);
			if (r & 1) rb = cmb(seg[--r], rb);
		}
		return cmb(ra, rb);
	}
};

void solve() {
	int n, q;
	cin >> n >> q;

	vi a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}

	vi x(n + 1, 0);
	rep(i, 0, n) {
		x[i + 1] = a[i] ? x[i] + 1 : x[i] - 1;
	}

	SegTree s(n + 1);
	rep(i, 0, n + 1) {
		s.upd(i, {x[i], x[i], 0, 0});
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;

		array<int, 4> res = s.query(l, r + 1);
		cout << res[0] << ' ' << res[1] << ' ' << res[2] << ' ' << res[3] << endl;
		cout << max(res[2] + x[l] - x[r + 1], res[3] + x[r + 1] - x[l]) << endl;

		int p = x[l], q = x[l], z = 0;
		rep(i, l, r + 2) {
			p = min(p, x[i]);
			q = max(q, x[i]);
			z = max({
				z,
				x[l] - x[r + 1] + 2 * (x[i] - p),
				x[r + 1] - x[l] + 2 * (q - x[i])
			});
		}
		// cout << p << ' ' << q << ' ' << z << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc = 1;
	cin >> tc;
	while (tc--) solve();
}
