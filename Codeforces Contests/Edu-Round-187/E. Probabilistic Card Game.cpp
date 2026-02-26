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
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = 998244353;

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
    int kth_one_end(int k) {return kth_one_end(k,0,n-1,1);}
    int kth_one_end(int k, int s, int e, int c) {
        if(seg[c][1] < k) { return -1; }      
        if(s == e) { return s; }
        int mid = (s+e)/2;
        if(seg[2*c][1] >= k) {// descend into right subtree
            return kth_one_end(k, s, mid, 2*c);} 
        else {return kth_one_end(k - seg[2*c][1], mid+1, e, 2*c+1);}
    }
};

int mpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int mdiv(int a, int b) {
	return a % MOD * mpow(b % MOD, MOD - 2) % MOD;
}

int get(SegTree<array<int, 4>> &s, vi &b, int i, int c) {
	int j = s.kth_one_end(i + 1);
	int res = 0;
	if (i > 0) {
		array<int, 4> p = s.query(0, j - 1);
		res = max(res, p[3] * p[1] - p[0]);
	}
	if (i < c - 1) {
		array<int, 4> p = s.query(j + 1, s.n - 1);
		res = max(res, p[0] - p[2] * p[1]);
	}
	return res;
}

int32_t main() {
	setup();
	int m;
	input(m);

	vi a(m);
	arrput(a);

	vi b = a;
	sort(all(b));
	SegTree<array<int, 4>> s(m, {0, 0, (int) 1e12 + 1, 0}, [](array<int, 4> a, array<int, 4> b) -> array<int, 4> {
		return {a[0] + b[0], a[1] + b[1], min(a[2], b[2]), max(a[3], b[3])};
	});
	int res = 0;
	rep(i, 0, m) {
		int j = lower_bound(all(b), a[i]) - b.begin();
		s.upd(j, {a[i], 1, a[i], a[i]});
		if (i + 1 < 3) {
			continue;
		}

		int l = 0, r = i, c = 1e18;
		while (l <= r) {
			int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
			int x = get(s, b, m1, i + 1), y = get(s, b, m2, i + 1);
			c = min({c, x, y});
			if (x == y) {
				l = m1 + 1;
				r = m2 - 1;
			}
			else if (x > y) {
				l = m1 + 1;
			}
			else {
				r = m2 - 1;
			}
		}
		print(mdiv(c, i - 1));
	}
}
