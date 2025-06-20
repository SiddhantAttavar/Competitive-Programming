#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
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
	setup();

	int n;
	input(n);

	vector<pair<int, int>> a(n);
	rep(i, 0, n) {
		input(a[i].first, a[i].second);
	}
	sort(a.begin(), a.end());

	vector<int> v(n);
	rep(i, 0, n) {
		v[i] = a[i].second;
	}
	sort(v.begin(), v.end());
	map<int, int> m;
	rep(i, 0, n) {
		if (!m.count(v[i])) {
			m[v[i]] = i;
		}
	}

	SegTree<pair<int, int>> s(n, {0, 0}, [](pair<int, int> a, pair<int, int> b) {
		return make_pair(a.first + b.first, a.second + b.second);
	});

	vector<pair<int, int>> l(n, {0, 0});
	__int128_t res = 0, k = 0, c = 0;
	for (auto [x, y] : a) {
		pair<int, int> p = s.query(0, m[y]), q = s.query(m[y] + 1, n - 1);
		res += c * x - k;
		res += p.second * y - p.first;
		res += q.first - q.second * y;
		l[m[y]].first += y;
		l[m[y]].second++;
		s.upd(m[y], {l[m[y]]});
		k += x;
		c++;
	}

	if (res == 0) {
		print(0);
		return 0;
	}

	string t;
	while (res) {
		t.push_back(res % 10 + '0');
		res /= 10;
	}
	reverse(t.begin(), t.end());
	print(t);
}
