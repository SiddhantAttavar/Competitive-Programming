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
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
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

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) { b++; // (for right inclusive)
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n);
		arrput(a);

		map<int, int> l, r;
		rep(i, 0, n) {
			if (!l.count(a[i])) {
				l[a[i]] = i;
			}
			r[a[i]] = i;
		}

		vi x(n);
		rep(i, 0, n) {
			x[i] = r[a[i]];
		}
		RMQ rmq(x);

		SegTree<int> s(n, n, [](int a, int b) {
			return min(a, b);
		});

		vi z(n, n), dp(n + 1, 0);
		rep(i, 0, n) {
			if (r[a[i]] != i) {
				continue;
			}
			int j = l[a[i]];
			z[i] = min(j, s.query(j, i));
			s.upd(i, z[i]);
			if (rmq.query(z[i], i) <= i) {
				dp[i + 1] = 1 + dp[z[i]];
			}
		}
		print(accumulate(all(dp), 0ll));
	}
}
