#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
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
		p += n; seg[p] = min(seg[p], val); for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
};

const int N = 2e5;
SegTree<double> seg(N + 1, 1e18, [](double a, double b) {
    return min(a, b);
});

void solve() {
    int n, m, l, x, y;
    cin >> n >> m >> l >> x >> y;

    vector<int> z;
    vector<pair<int, int>> v(n);
    rep(i, 0, n) {
        int s, t;
        cin >> s >> t;
        v[i] = {s, t};
        z.push_back(s);
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return (a.second - a.first) > (b.second - b.first);
    });

    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    
    for (auto [s, t] : v) {
        int k = lower_bound(z.begin(), z.end(), s) - z.begin();
        seg.upd(k, min(seg.query(0, k), ((l - t) * 1.0) / y + ((t - s) * 1.0) / x));
    }

    cout << fixed << setprecision(15);
    rep(i, 0, m) {
        int p;
        cin >> p;
        double res = ((l - p) * 1.0) / y;
        int k = upper_bound(z.begin(), z.end(), p) - z.begin() - 1;
        if (k >= 0) {
            res = min(res, seg.query(0, k));
        }
        cout << res << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
