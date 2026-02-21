#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 7e18;

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

int get(vi &v, int x) {
    return lower_bound(all(v), x) - v.begin();
}

void upd(int y, vector<multiset<int>> &uv, SegTree<int> &xy) {
    if (uv[y].empty()) {
        xy.upd(y, INF);
        return;
    }
    xy.upd(y, *uv[y].begin());
}

void solve() {
    int n, q, a, b;
    cin >> n >> q >> a >> b;

    vector<array<int, 3>> p(n);
    vi x, y;
    rep(i, 0, n) {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
        x.push_back(p[i][0]);
        y.push_back(p[i][1]);
    }

    vector<array<int, 3>> s(q);
    rep(i, 0, q) {
        cin >> s[i][0] >> s[i][1];
        s[i][2] = i;
        x.push_back(s[i][0]);
        y.push_back(s[i][1]);
    }

    sort(all(x));
    x.erase(unique(all(x)), x.end());
    sort(all(y));
    y.erase(unique(all(y)), y.end());

    int N = sz(x), M = sz(y);
    vector<multiset<int>> uv(M), uV(M), Uv(M), UV(M);
    SegTree<int> xy(M, INF, [](int a, int b) {
        return min(a, b);
    }), xY(M, INF, [](int a, int b) {
        return min(a, b);
    }), Xy(M, INF, [](int a, int b) {
        return min(a, b);
    }), XY(M, INF, [](int a, int b) {
        return min(a, b);
    });
    
    vector<vector<pii>> P(N), S(N);
    for (auto [s, t, c] : p) {
        int i = get(x, s), j = get(y, t);
        Uv[j].insert(a * s - b * t + c);
        upd(j, Uv, Xy);
        UV[j].insert(a * s + b * t + c);
        upd(j, UV, XY);
        P[i].push_back({t, c});
    }
    for (auto [a, b, j] : s) {
        int i = get(x, a);
        S[i].push_back({b, j});
    }

    vi res(q);
    rep(i, 0, N) {
        int s = x[i];
        for (auto [t, k] : S[i]) {
            int j = get(y, t);
            res[k] = min({
                a * s + b * t + xy.query(0, j),
                a * s - b * t + xY.query(j, M - 1),
                -a * s + b * t + Xy.query(0, j),
                -a * s - b * t + XY.query(j, M - 1)
            });
        }
        for (auto [t, c] : P[i]) {
            int j = get(y, t);
            uv[j].insert(-a * s - b * t + c);
            upd(j, uv, xy);
            uV[j].insert(-a * s + b * t + c);
            upd(j, uV, xY);
            Uv[j].erase(Uv[j].find(a * s - b * t + c));
            upd(j, Uv, Xy);
            UV[j].erase(UV[j].find(a * s + b * t + c));
            upd(j, UV, XY);
        }
    }
    for (int i : res) {
        cout << i << endl;
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
