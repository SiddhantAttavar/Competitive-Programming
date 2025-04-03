#include <bits/stdc++.h>
using namespace std;
template<typename T, typename ...S> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename ...S> inline void input(T& inVar, S& ...args) {cin >> inVar; input(args ...);}
template<typename T, typename ...S> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename ...S> inline void print(T outVar, S& ...args) {cout << outVar << ' '; print(args ...);}
#define range(ind, start, stop) for (auto ind = start; ind < stop; ind++)
#define arrPut(arr) for (auto &inVar : arr) {cin >> inVar;}
#define arrPrintt(arr) for (auto outVar : arr) {cout << inVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

using ll = long long;
using db = double;
using str = string;
using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t S> using AR = array<T, S>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(s) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x), sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) FOR(_, a)
#define each(a, x) for (auto a : x)

const int MOD = (int) 1e9 + 7;
const db PI = acos((db) -1);
mt19937 rng(0);
tcT> bool ckmin(T& a, T& b) {return b < a ? a = b, 1 : 0;};
tcT> bool ckmax(T& a, T& b) {return b > a ? a = b, 1 : 0;};

tcT> struct SegTree {
	T ID;
	T (*cmb)(T, T);
	int n; V<T> seg;
	SegTree(int _n, T id, T func(T, T)) {
		for (n = 1; n < _n; ) {
			n *= 2;
		}
		ID = id;
		cmb = func;
		seg.assign(2*n, ID);
	}

	void pull(int p) {
		seg[p] = cmb(seg[2*p], seg[2*p+1]);
	}

	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p /= 2) pull(p);
	}

	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra, seg[l++]);
			if (r&1) rb = cmb(rb, seg[--r]);
		}
		return cmb(ra, rb);
	}
};

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<int> a(n);
	arrPut(a);
	SegTree< pair<int, int> > s(n, {1e9, 1}, [](pair<int, int> a, pair<int, int> b){
		if (a.first == b.first) {
			return make_pair(a.first, a.second + b.second);
		}
		if (a.first < b.first) {
			return a;
		}
		return b;
	});

	range(i, 0, n) {
		s.upd(i, {a[i], 1});
	}

	range(i, 0, m) {
		int x, y, z;
		input(x, y, z);

		if (x == 1) {
			s.upd(y, {z, 1});
		}
		else {
			pair<int, int> p = s.query(y, z - 1);
			print(p.first, p.second);
		}
	}
}
