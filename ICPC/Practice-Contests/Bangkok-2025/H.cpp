#include <bits/stdc++.h>
using namespace std;

// #define int long long
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
	void upd(int p, T val) { p += n; // set val at position p
		seg[p] = cmb(seg[p], val); for (p /= 2; p; p /= 2) pull(p); }
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

    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    const int N = 1e5;
    vector<vector<pii>> dp(1, vector<pii>(n, {0, -1}));
    while (max_element(all(dp.back()))->first != -1) {
        vector<pii> ndp(n, {-1, -1});
        SegTree<pii> s(N + 1, {-1, -1}, [](pii a, pii b) {
            return max(a, b);
        });
        rep(i, 0, n) {
            if (dp.back()[i].first == -1) {
                continue;
            }
            int y = a[i] + dp.back()[i].first + 1;
            if (y <= N) {
                s.upd(y, {a[i], i});
            }
            auto [x, j] = s.query(0, a[i]);
            if (x != -1) {
                ndp[i] = {a[i] - x, j};
            }
        }
        dp.push_back(ndp);
    }
    
    dp.pop_back();
    int u = max_element(all(dp.back())) - dp.back().begin();
    vi res;
    while (u != -1) {
        res.push_back(u);
        u = dp.back()[u].second;
        dp.pop_back();
    }
    cout << sz(res) << endl;
    reverse(all(res));
    for (int i : res) {
        cout << i + 1 << ' ';
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
