#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> l(n), r(n);
		rep(i, 0, n) {
			input(l[i], r[i]);
		}

		set<int> v(l.begin(), l.end());
		v.insert(r.begin(), r.end());
		map<int, int> m;
		int z = 0;
		for (int i : v) {
			m[i] = z;
			z++;
		}

		vector<vector<int>> a(n);
		rep(i, 0, n) {
			a[i] = {m[l[i]], m[r[i]], r[i] - l[i]};
		}
		sort(a.begin(), a.end());

		vector<pair<int, int>> t(z, {2e9, 0});
		SegTree<pair<int, int>> s(z, make_pair((int) 2e9, 0ll), [](pair<int, int> a, pair<int, int> b) {
			return make_pair(min(a.first, b.first), max(a.second, b.second));
		});
		int res = 0;
		for (vector<int> i : a) {
			t[i[1]] = {min(t[i[1]].first, i[2]), max(t[i[1]].second, i[2])};
			s.upd(i[1], t[i[1]]);
			pair<int, int> p = s.query(0, i[1]);
			res = max({res, i[2] - p.first, p.second - i[2]});
		}
		print(res);
	}
}
