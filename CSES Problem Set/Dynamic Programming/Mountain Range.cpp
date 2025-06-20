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

	vector<int> a(n);
	arrput(a);

	vector<int> v(n);
	rep(i, 0, n) {
		v[i] = i;
	}
	sort(v.begin(), v.end(), [&](int x, int y) {
		return a[x] < a[y];
	});

	vector<int> p(n), q(n);
	stack<int> l;
	rep(i, 0, n) {
		while (!l.empty() and a[l.top()] < a[i]) {
			l.pop();
		}
		if (l.empty()) {
			p[i] = 0;
		}
		else {
			p[i] = l.top() + 1;
		}
		l.push(i);
	}
	while (!l.empty()) {
		l.pop();
	}
	for (int i = n - 1; i >= 0; i--) {
		while (!l.empty() and a[l.top()] < a[i]) {
			l.pop();
		}
		if (l.empty()) {
			q[i] = n - 1;
		}
		else {
			q[i] = l.top() - 1;
		}
		l.push(i);
	}

	SegTree<int> s(n, 0, [](int a, int b) {
		return max(a, b);
	});
	for (int i : v) {
		s.upd(i, s.query(p[i], q[i]) + 1);
	}
	print(s.query(0, n - 1));
}
