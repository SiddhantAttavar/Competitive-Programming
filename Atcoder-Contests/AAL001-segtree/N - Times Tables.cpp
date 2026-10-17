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

	int n, q;
	input(n, q);

	vector<vector<pii>> x(n), y(n);
	rep(i, 0, q) {
		int a, b, c, d;
		input(a, b, c, d);
		x[a - 1].push_back({b - 1, d - 1});
		y[c - 1].push_back({b - 1, d - 1});
	}

	LazySeg<pii, int, 1 << 18> s({1e18, 0}, 0, [](pii a, pii b) -> pii {
		if (a.first != b.first) {
			return min(a, b);
		}
		return {a.first, a.second + b.second};
	}, [](int ind,int L,int R,vector<pii>&seg,vector<int>&lazy) {
		/// modify values for current node
		seg[ind].first += lazy[ind]; // dependent on operation
		if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
		lazy[ind] = 0; /// prop to children
	});

	rep(i, 0, n) {
		s.seg[i + (1 << 18)] = {0, i + 1};
	}
	s.build();

	int res = 0;
	rep(i, 0, n) {
		for (auto [l, r] : x[i]) {
			s.upd(l, r, 1);
		}
		auto [a, b] = s.query(0, n - 1);
		if (a == 0) {
			res = (res + (i + 1) * (b % MOD)) % MOD;
		}
		for (auto [l, r] : y[i]) {
			s.upd(l, r, -1);
		}
	}
	print(res);
}
