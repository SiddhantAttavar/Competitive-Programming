#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ll long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((ll)((x).size()))
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

const int N = 1 << 18;

void insert(int x, int y, int c, int z, map<pair<int, int>, int> &m, vector<set<int>> &v, SegTree<pair<int, int>> &s, vector<int> &p) {
    if (m.count({y, c})) {
        m[{y, c}] = x;
        return;
    }
    
    m[{y, c}] = x;
    v[c].insert(y);
    int l = max(0ll, y - z), r = y + 1;
    set<int>::iterator i = v[c].find(y);
    if (i == v[c].end()) return;
    if (i != v[c].begin()) {
        l = max(l, *prev(i) + 1);
    }
    if (next(i) != v[c].end()) {
        r = min(r, *next(i) - z);
    }
    if (l < r) {
        p[l]++;
        p[r]--;
        s.upd(l, {max(0ll, p[l]), p[l]});
        s.upd(r, {max(0ll, p[r]), p[r]});
    }
}

void remove(int x, int y, int c, int z, map<pair<int, int>, int> &m, vector<set<int>> &v, SegTree<pair<int, int>> &s, vector<int> &p) {
    if (m[{y, c}] != x) {
        return;
    }

    m.erase({y, c});
    int l = max(0ll, y - z), r = y + 1;
    set<int>::iterator i = v[c].find(y);
    if (i == v[c].end()) return;
    if (i != v[c].begin()) {
        l = max(l, *prev(i) + 1);
    }
    if (next(i) != v[c].end()) {
        r = min(r, *next(i) - z);
    }
    if (l < r) {
        p[l]--;
        p[r]++;
        s.upd(l, {max(0ll, p[l]), p[l]});
        s.upd(r, {max(0ll, p[r]), p[r]});
    }
    v[c].erase(i);
}

bool check(vector<int> &x, vector<int> &y, vector<int> &c, int z, int k) {
    SegTree<pair<int, int>> s(N, {0, 0}, [](pair<int, int> a, pair<int, int> b) {
        return make_pair(max(a.first, a.second + b.first), a.second + b.second);
    });
    vector<int> p(N, 0);
    int n = x.size();
    vector<vector<pair<int, int>>> a(N);
    rep(i, 0, n) {
        a[x[i]].push_back({y[i], c[i]});
    }

    map<pair<int, int>, int> m;
    vector<set<int>> v(k);
    rep(x, 0, z + 1) {
        for (auto [y, c] : a[x]) {
            insert(x, y, c, z, m, v, s, p);
        }
    }

    if (s.query(0, N - 1).first == k) {
        return true;
    }

    rep(x, z + 1, N) {
        for (auto [y, c] : a[x]) {
            insert(x, y, c, z, m, v, s, p);
        }

        for (auto [y, c] : a[x - z - 1]) {
            remove(x - z - 1, y, c, z, m, v, s, p);
        }

        if (s.query(0, N - 1).first == k) {
            return true;
        }
    }

    return false;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<int> x(n), y(n), c(n);
    rep(i, 0, n) {
        cin >> x[i] >> y[i] >> c[i];
        x[i]--;
        y[i]--;
        c[i]--;
    }

    int l = 0, r = N, res = N;
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(x, y, c, m, k)) {
            res = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    cout << res << endl;
}
