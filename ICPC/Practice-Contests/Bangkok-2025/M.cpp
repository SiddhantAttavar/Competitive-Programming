#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T> struct SegTree { // cmb(ID,b) = b
	T ID; T (*cmb)(T a, T b);
	int n; vector<T> seg;
	SegTree(int _n, T id, T _cmb(T, T)) {
		ID = id; cmb = _cmb;
		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,ID); 
	}
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
};


void solve() {
    int n;
    cin >> n;

    vi p(n), q(n);
    rep(i, 0, n) {
        cin >> p[i];
        q[p[i] - 1] = i;
    }

    SegTree<int> s(n, 0, [](int a, int b) {
        return a + b;
    });
    rep(i, 0, n) {
        s.upd(i, 1);
    }

    vi x(n, 0);
    int u = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        int v = q[i];
        if (u < v) {
            x[i] = s.query(0, u);
            u = n - 1;
        }
        x[i] += s.query(v, u);
        s.upd(v, 0);
        u = v;
    }

    rep(i, 0, n) {
        cout << x[i] << ' ';
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
