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

#define ld long double
const ld inf = 1/.0;

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
    void insert(int i, ld k, ld m, int c = 1, int l = 0, int r = -1) {
        if (r == -1) {
            insert(i, k, m, c, l, n - 1);
            return;
        }
        seg[c].add(-k, -m);
        if (l == r) {
            return;
        }
        int u = (l + r) / 2;
        if (i <= u) {
            insert(i, k, m, 2 * c, l, u);
        }
        else {
            insert(i, k, m, 2 * c + 1, u + 1, r);
        }
    }
    ld get(int s, int e, int y, int c = 1, int l = 0, int r = -1) {
        if (r == -1) {
            return get(s, e, y, c, l, n - 1);
        }
        if (l > e or r < s or seg[c].empty()) {
            return inf;
        }
        if (s <= l and r <= e) {
            return -seg[c].query(y);
        }
        int u = (l + r) / 2;
        return min(get(s, e, y, 2 * c, l, u), get(s, e, y, 2 * c + 1, u + 1, r));
    }
};

struct Line {
    mutable ld k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ld x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    ld inf = 1/.0;
    ld div(ld a, ld b) {
        return a / b;
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ld k, ld m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ld query(ld x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), v(n);
    rep(i, 0, n) {
        cin >> x[i] >> v[i];
    }

    int q;
    cin >> q;

    vector<pair<int, int>> l;
    rep(i, 0, q) {
        char c;
        cin >> c;

        if (c == '+') {
            int x, v;
            cin >> x >> v;
            l.push_back({x, v});
        }
        else {
            int y;
            cin >> y;
            l.push_back({y, -1});
        }
    }

    vector<int> a = x;
    for (auto [x, v] : l) {
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    map<int, int> m;
    for (int i : a) {
        m[i] = sz(m);
    }

    SegTree<LineContainer> s(sz(m), {}, [](LineContainer a, LineContainer b) {
        LineContainer res = a;
        for (Line l : b) {
            res.add(l.k, l.m);
        }
        return res;
    }), t(sz(m), {}, [](LineContainer a, LineContainer b) {
        LineContainer res = a;
        for (Line l : b) {
            res.add(l.k, l.m);
        }
        return res;
    });

    rep(i, 0, n) {
        ld k = 1.0L / v[i], c = (x[i] * 1.0L) / v[i];
        s.insert(m[x[i]], k, -c);
        t.insert(m[x[i]], -k, c);
    }

    cout << fixed << setprecision(20);
    for (auto [x, v] : l) {
        if (v != -1) {
            ld k = 1.0L / v, c = (x * 1.0L) / v;
            s.insert(m[x], k, -c);
            t.insert(m[x], -k, c);
        }
        else {
            cout << max(0.0L, min(s.get(0, m[x], x), t.get(m[x], sz(m) - 1, x))) << endl;
        }
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}

