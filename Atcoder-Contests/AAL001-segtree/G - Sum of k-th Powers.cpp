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
const int MOD = 998244353;
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

template<class T, class U, int SZ> struct LazySeg { 
	// static_assert(pct(SZ) == 1); // SZ must be power of 2
	const T ID1; T (*cmb)(T a, T b);
	vector<T> seg; vector<U> lazy;
	void (*push)(int,int,int,vector<T>&,vector<U>&) = 
		[&](int ind,int L,int R,vector<T>&seg,vector<U>&lazy) {
		/// modify values for current node
		seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
		if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
		lazy[ind] = 0; /// prop to children
	}; // recalc values for current node
	LazySeg(T id1, U id2, T _cmb(T, T), void _push(int,int,int,vector<T>&,vector<U>&)):
		ID1(id1),cmb(_cmb),push(_push),seg(2*SZ,id1),lazy(2*SZ,id2){}
	void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}
	void build() { for(int i=SZ-1;i>=1;i--) pull(i); }
	void upd(int lo,int hi,U inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R,seg,lazy); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R,seg,lazy); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R,seg,lazy); if (lo > R || L > hi) return ID1;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
			query(lo,hi,2*ind+1,M+1,R));
	}
};

int32_t main() {
	setup();

	LazySeg<array<int, 5>, int, 1 << 18> s({0, 0, 0, 0, 0}, 0, [](array<int, 5> a, array<int, 5> b) -> array<int, 5> {
		return {(a[0] + b[0]) % MOD, (a[1] + b[1]) % MOD, (a[2] + b[2]) % MOD, (a[3] + b[3]) % MOD, (a[4] + b[4]) % MOD};
	}, [] (int ind,int L,int R,vector<array<int, 5>>&seg,vector<int>&lazy) {
		/// modify values for current node
		int x = lazy[ind] % MOD , x2 = x * x % MOD, x3 = x2 * x % MOD, x4 = x3 * x % MOD;
		seg[ind] = {
			seg[ind][0],
			(seg[ind][1] + seg[ind][0] * x % MOD) % MOD,
			(seg[ind][2] + seg[ind][1] * 2 % MOD * x % MOD + seg[ind][0] * x2 % MOD) % MOD,
			(seg[ind][3] + seg[ind][2] * 3 % MOD * x % MOD + seg[ind][1] * 3 % MOD * x2 % MOD + seg[ind][0] * x3 % MOD) % MOD,
			(seg[ind][4] + seg[ind][3] * 4 % MOD * x % MOD + seg[ind][2] * 6 % MOD * x2 % MOD + seg[ind][1] * 4 % MOD * x3 % MOD + seg[ind][0] * x4 % MOD) % MOD
		}; // dependent on operation
		if (L != R) {lazy[2*ind] = (lazy[2*ind] + lazy[ind]) % MOD; lazy[2*ind+1] = (lazy[2*ind+1] + lazy[ind]) % MOD;}
		lazy[ind] = 0; /// prop to children
	});

	int n, q;
	input(n, q);

	vi a(n);
	arrput(a);
	rep(i, 0, n) {
		int x = a[i] % MOD, x2 = x * x % MOD, x3 = x2 * x % MOD, x4 = x3 * x % MOD;
		s.seg[i + (1 << 18)] = {1, x, x2, x3, x4};
	}
	s.build();

	while (q--) {
		int o, l, r, x;
		input(o, l, r, x);

		l--;
		r--;

		if (o == 1) {
			s.upd(l, r, x);
		}
		else {
			print(s.query(l, r)[x]);
		}
	}
}
