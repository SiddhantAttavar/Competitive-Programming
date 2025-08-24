#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

#define vi vector<int>
#define sz(x) (int) x.size()

array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}

/**
 * Author: Simon Lindholm
 * Date: 2015-03-15
 * License: CC0
 * Source: own work
 * Description: Self-explanatory methods for string hashing.
 * Status: stress-tested
 */
#define ll int

// Arithmetic mod 2^64-1. 2x slower than mod 2^64 and more
// code, but works on evil test data (e.g. Thue-Morse, where
// ABBA... and BAAB... of length 2^10 hash the same mod 2^64).
// "typedef ull H;" instead if you think test data is random,
// or work mod 10^9+7 if the Birthday paradox is not a problem.
typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

vector<H> getHashes(string& str, int length) {
	if (sz(str) < length) return {};
	H h = 0, pw = 1;
	rep(i,0,length)
		h = h * C + str[i], pw = pw * C;
	vector<H> ret = {h};
	rep(i,length,sz(str)) {
		ret.push_back(h = h * C + str[i] - pw * str[i-length]);
	}
	return ret;
}

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

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
    int q1(int l, int r, int ql, int qr, int c, int k) {
        if (r < ql or l > qr) {
            return -1;
        }
        if (seg[c] > k) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int m = (l + r) / 2;
        int x = q1(m + 1, r, ql, qr, c, k);
        if (x != -1) {
            return x;
        }
        return q1(l, m, ql, qr, c, k);
    }
    int q2(int l, int r, int ql, int qr, int c, int k) {
        if (r < ql or l > qr) {
            return -1;
        }
        if (seg[c] < k) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int m = (l + r) / 2;
        int x = q2(l, m, ql, qr, c, k);
        if (x != -1) {
            return x;
        }
        return q2(m + 1, r, ql, qr, c, k);
    }
};

bool check(int l, int r, int m, int n, HashInterval &a, HashInterval &b) {
    // cout << l << ' ' << r << ' ' << m << endl;
    // cout << a.hashInterval(l, l + m).get() << ' ' << b.hashInterval(n - r - 1, n - (r - m + 1)).get() << endl;
    return a.hashInterval(l, l + m).get() == b.hashInterval(n - r - 1, n - (r - m + 1)).get();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string s;
    cin >> n >> s;

    string t = s;
    reverse(t.begin(), t.end());

    HashInterval a(s), b(t);

    SegTree<int> uo(n, 0, [](int a, int b) {
        return min(a, b);
    }), vo(n, 0, [](int a, int b) {
        return max(a, b);
    }), ue(n, 0, [](int a, int b) {
        return min(a, b);
    }), ve(n, 0, [](int a, int b) {
        return max(a, b);
    });
    array<vi, 2> z = manacher(s);
    rep(i, 0, n) {
        ue.upd(i, i - z[0][i] + 1);
        ve.upd(i, i + z[0][i]);
        uo.upd(i, i - z[1][i]);
        vo.upd(i, i + z[1][i]);
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int s = 0, t = r - l + 1, x = -1;
        while (s <= t) {
            int m = (s + t) / 2;
            if (check(l, r, m, n, a, b)) {
                s = m + 1;
            }
            else {
                x = m - 1;
                t = m - 1;
            }
        }
        // cout << x << endl;

        if (x == -1) {
            cout << "0 0\n";
            continue;
        }

        int ae = ve.q2(0, n - 1, l + x, r - x, 1, l + x);
        int ao = vo.q2(0, n - 1, l + x, r - x, 1, l + x);
        int be = ue.q1(0, n - 1, l + x, r - x, 1, r - x);
        int bo = uo.q1(0, n - 1, l + x, r - x, 1, r - x);
        
        int zae = (r - l + 1) - (2 * x + 2 * (ae - (l + x)));
        int zao = (r - l + 1) - (2 * x + 2 * (ao - (l + x)) + 1);
        int zbe = (r - l + 1) - (2 * x + 2 * (r - x - be));
        int zbo = (r - l + 1) - (2 * x + 2 * (r - x - bo) + 1);
        // cout << bo << ' ' << zbo << endl;

        int res = min({zae, zao, zbe, zbo});
        cout << res << ' ' << (res == zao) + (res == zae) + (res == zbe) + (res == zbo) << endl;
    }
}
