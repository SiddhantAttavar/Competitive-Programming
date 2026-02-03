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

const int N = 1e6;
int K = 27;
vi powk(N + 1, 1);

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
	rep(i, 1, N + 1) {
		powk[i] = powk[i - 1] * K % MOD;
	}

	int n, m;
	input(n, m);

	SegTree<array<int, 3>> s(n, {0, 0, 0}, [](array<int, 3> a, array<int, 3> b) -> array<int, 3> {
		return {
			(a[0] * powk[b[2]] + b[0]) % MOD,
			(a[1] + powk[a[2]] * b[1]) % MOD,
			a[2] + b[2]
		};
	});

	string a;
	input(a);
	rep(i, 0, n) {
		s.upd(i, {a[i] - 'a', a[i] - 'a', 1});
	}
	while (m--) {
		int o;
		input(o);

		if (o == 1) {
			int i;
			char c;
			input(i, c);
			s.upd(i - 1, {c - 'a', c - 'a', 1});
		}
		else {
			int l, r;
			input(l, r);
			auto [p, q, x] = s.query(l - 1, r - 1);
			if (p == q) {
				print("YES");
			}
			else {
				print("NO");
			}
		}
	}
}
