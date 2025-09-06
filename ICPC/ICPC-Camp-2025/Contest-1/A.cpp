#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

#define sz(x) (int) x.size()
#define ll long long
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<string> a(m), b(n);
    rep(i, 0, m) {
        cin >> a[i];
    }
    rep(i, 0, n) {
        cin >> b[i];
    }
    sort(a.begin(), a.end(), [](string a, string b) {
        return a.size() < b.size();
    });
    sort(b.begin(), b.end(), [](string a, string b) {
        return a.size() < b.size();
    });

    map<int, int> x, y;
    map<int, set<int>> p, q;
    rep(i, 0, m) {
        HashInterval h(a[i]);
        rep(j, 0, a[i].size()) {
            int s = h.hashInterval(0, j + 1).get();
            int t = h.hashInterval(j + 1, a[i].size()).get();
            if (x.count(s)) {
                p[t].insert(i);
                p[t].insert(x[s]);
            }
        }
        x[h.hashInterval(0, a[i].size()).get()] = i;
    }
    rep(i, 0, n) {
        HashInterval h(b[i]);
        rep(j, 0, b[i].size()) {
            int s = h.hashInterval(0, j + 1).get();
            int t = h.hashInterval(j + 1, b[i].size()).get();
            if (y.count(t)) {
                q[s].insert(i);
                q[s].insert(y[t]);
            }
        }
        y[h.hashInterval(0, b[i].size()).get()] = i;
    }

    vector<bool> s(m, true), t(n, true);
    for (auto [k, v] : p) {
        if (!q.count(k)) {
            continue;
        }
        for (int i : v) {
            s[i] = false;
        }
        for (int i : q[k]) {
            t[i] = false;
        }
    }
    cout << accumulate(s.begin(), s.end(), 0ll) << ' ' << accumulate(t.begin(), t.end(), 0ll) << endl;
}
