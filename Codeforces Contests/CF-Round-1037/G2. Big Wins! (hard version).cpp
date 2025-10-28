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
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
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

		vector<int> a(n);
		arrput(a);

		vector<vector<int>> v(n);
		rep(i, 0, n) {
			a[i]--;
			v[a[i]].push_back(i);
		}

		vector<int> l(n, 0), r(n, n - 1);
		stack<int> s;
		rep(i, 0, n) {
			while (!s.empty() and a[s.top()] >= a[i]) {
				s.pop();
			}
			if (!s.empty()) {
				l[i] = s.top() + 1;
			}
			s.push(i);
		}
		while (!s.empty()) {
			s.pop();
		}
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() and a[s.top()] >= a[i]) {
				s.pop();
			}
			if (!s.empty()) {
				r[i] = s.top() - 1;
			}
			s.push(i);
		}

		int res = 0;
		vector<int> x(n, 0), y(n, n - 1);
		SegTree<array<int ,3>> t(n, {0, 0, 0}, [](array<int, 3> a, array<int, 3> b) {
			return array<int, 3>{a[0] + b[0], max(a[1], a[0] + b[1]), max(a[2] + b[0], b[2])};
		});
		rep(i, 0, 20) {
			vector<vector<int>> z(n);
			vector<int> f(n, -1);
			bool flag = false;
			rep(j, 0, n) {
				t.seg[j + t.n] = {-1, 0, 0};
				if (x[j] <= y[j]) {
					flag = true;
					z[(x[j] + y[j]) / 2].push_back(j);
				}
			}
			if (!flag) {
				break;
			}
			for (int j = t.n - 1; j > 0; j--) {
				t.pull(j);
			}
			for (int j = n - 1; j >= 0; j--) {
				for (int k : v[j]) {
					f[k] = 1;
					t.upd(k, {1, 1, 1});
				}
				for (int k : z[j]) {
					int u = f[k] + (k < r[k] ? t.query(k + 1, r[k])[1] : 0) + (k > l[k] ? t.query(l[k], k - 1)[2] : 0);
					if (u >= 0) {
						res = max(res, j - a[k]);
						x[k] = j + 1;
					}
					else {
						y[k] = j - 1;
					}
				}
			}
		}
		print(res);
	}
}
