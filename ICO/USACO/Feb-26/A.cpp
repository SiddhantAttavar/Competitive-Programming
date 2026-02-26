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

		vi a(n);
		arrput(a);
		rep(i, 0, n) {
			a[i]--;
		}

		SegTree<int> s(n, 0, [](int a, int b) {
			return a + b;
		});

		map<int, int> u, v;
		int c = 0, z = 0, p = 0, q = 0, x = 0, y = 0;
		rep(j, 0, n) {
			if (a[j] > j) {
				z += a[j] - j;
				q++;
			}
			else {
				z += j - a[j];
				p++;
			}

			c += s.query(a[j], n - 1);
			s.upd(a[j], 1);
			u[a[j] - j]++;
		}

		vi res;
		rep(i, 0, n) {
			if (2 * c <= z) {
				res.push_back(i);
			}

			c -= n - a[n - i - 1] - 1;
			c += a[n - i - 1];

			p--;
			z -= n - 1 - a[n - i - 1];
			u[a[n - i - 1] - (n - i - 1)]--;
			v[a[n - i - 1] - (n - i - 1) + n]++;
			z += a[n - i - 1] + 1;
			y++;
			// print(z, p, q, x, y);

			z += p - q + x - y;
			q -= u[i + 1];
			p += u[i + 1];
			y -= v[i + 1];
			x += v[i + 1];
		}
		print(sz(res));
		rep(i, 0, sz(res) - 1) {
			cout << res[i] << ' ';
		}
		if (!res.empty()) {
			cout << res.back();
		}
		cout << endl;
	}
}
