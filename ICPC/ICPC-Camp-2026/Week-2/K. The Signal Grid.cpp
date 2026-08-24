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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

#define ll int

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

const int N = 1e5;
LineContainer seg[4 * N];

void build(int l, int r, int c, vector<pii> &v) {
	if (l == r) {
		seg[c].add(-v[l].first, -v[l].second);
		return;
	}
	int m = (l + r) / 2;
	build(l, m, 2 * c, v);
	build(m + 1, r, 2 * c + 1, v);
	for (auto [x, y, _] : seg[2 * c]) {
		seg[c].add(x, y);
	}
	for (auto [x, y, _] : seg[2 * c + 1]) {
		seg[c].add(x, y);
	}
}

int query(int l, int r, int s, int e, int c, int x) {
	if (l > e or r < s) {
		return 1e18;
	}
	if (l <= s and e <= r) {
		return -seg[c].query(x);
	}
	int m = (s + e) / 2;
	return min(query(l, r, s, m, 2 * c, x), query(l, r, m + 1, e, 2 * c + 1, x));
}

int32_t main() {
	setup();

	int n;
	input(n);

	vi a(n);
	arrput(a);

	vi p(n + 1, 0);
	rep(i, 0, n) {
		p[i + 1] = p[i] + a[i];
	}

	vector<pii> v(n);
	rep(i, 0, n) {
		v[i] = {a[i], -p[i] + i * a[i]};
	}
	build(0, n - 1, 1, v);

	int m;
	input(m);
	while (m--) {
		int i, j;
		input(i, j);
		i--;
		j--;
		print(p[j + 1] + query(j - i, j, 0, n - 1, 1, i - j));
	}
}
