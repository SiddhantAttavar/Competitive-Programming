#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
const int MOD = 1e9 + 7;

template<typename T> struct SegTree { // cmb(ID,b) = b
	T ID; T (*cmb)(T &a, T &b);
	int n; vector<T> seg;
	SegTree(int _n, T id, T _cmb(T&, T&)) {
		ID = id; cmb = _cmb;
		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,ID); 
	}
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    void get(vector<int> &res, vector<pair<int, int>> &l, int x) {
        for (int i = l.size() - 1; i >= 0; i--) {
            if (l[i].first < x) {
                return;
            }
            res.push_back(l[i].second);
        }
    }
	void query(int l, int r, int x, vector<int> &res) {	// zero-indexed, inclusive
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) get(res, seg[l++], x);
			if (r&1) get(res, seg[--r], x);
		}
	}
};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<pair<pair<int, int>, int>> v(n);
    rep(i, 0, n) {
        int x, y;
        cin >> x >> y;
        v[i] = {{2 * y - x, 2 * y + x}, i + 1};
    }
    sort(v.begin(), v.end());
    vector<pair<int, int>> a;
    for (auto [p, i] : v) {
        a.push_back({p.second, i});
    }

    SegTree<vector<pair<int, int>>> s(v.size(), {}, [](vector<pair<int, int>> &a, vector<pair<int, int>> &b) {
        vector<pair<int, int>> res(a.size() + b.size());
        merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());
        return res;
    });

    rep(i, 0, v.size()) {
        s.seg[i + s.n] = {a[i]};
    }
    for (int i = s.n - 1; i >= 0; i--) {
        s.pull(i);
    }

    int p = 0;
    while (q--) {
        int a, b;
        cin >> a >> b;
        
        int x, y;
        tie(x, y) = make_pair(-1 - ((p + a) % MOD), (p + b) % MOD);

        int l, r;
        tie(l, r) = make_pair(2 * y + x, 2 * y - x);
        // cout << l << ' ' << r << endl;
        r = upper_bound(v.begin(), v.end(), make_pair(make_pair(r, (int) 1e18), (int) 1e18)) - v.begin() - 1;
        
        vector<int> v;
        s.query(0, r, l, v);
        sort(v.begin(), v.end());
        int res = 0, c = 1;
        rep(i, 0, v.size()) {
            // cout << v[i] << endl;
            res = (res + v[i] * c) % MOD;
            c = c * 5782344 % MOD;
        }
        cout << res << endl;
        p = res;
    }
}
