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
	int first(int l, int &t, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R,seg,lazy);
		if (R < l) {
			return -1;
		}
		if (L >= l and seg[ind][3] <= t) {
			t -= seg[ind][0];
			return -1;
		}
		if (L == R) {
			return L;
		}
		int M = (L + R) / 2;
		int res = first(l, t, 2 * ind, L, M);
		if (res != -1) {
			return res;
		}
		return first(l, t, 2 * ind + 1, M + 1, R);
	}
};

int32_t main() {
	setup();

	LazySeg<array<int, 6>, array<int, 3>, 1 << 17> s({0, 0, 0, 0, 0, 0}, {0, 1, 2}, [](array<int, 6> a, array<int, 6> b) -> array<int, 6> {
		return {a[0] + b[0], a[1] + b[1], a[2] + b[2], max(a[3], a[0] + b[3]), max(a[4], a[1] + b[4]), max(a[5], a[2] + b[5])};
	}, [](int ind,int L,int R,vector<array<int, 6>>&seg,vector<array<int, 3>>&lazy) {
		/// modify values for current node
		seg[ind] = {seg[ind][lazy[ind][0]], seg[ind][lazy[ind][1]], seg[ind][lazy[ind][2]], seg[ind][lazy[ind][0] + 3], seg[ind][lazy[ind][1] + 3], seg[ind][lazy[ind][2] + 3]}; // dependent on operation
		if (L != R) {
			lazy[2*ind] = {lazy[2*ind][lazy[ind][0]], lazy[2*ind][lazy[ind][1]], lazy[2*ind][lazy[ind][2]]};
			lazy[2*ind+1] = {lazy[2*ind+1][lazy[ind][0]], lazy[2*ind+1][lazy[ind][1]], lazy[2*ind+1][lazy[ind][2]]};
		}
		lazy[ind] = {0, 1, 2}; /// prop to children
	});

	int n, q;
	input(n, q);

	vi a(n), b(n), c(n);
	arrput(a);
	arrput(b);
	arrput(c);

	rep(i, 0, n) {
		s.seg[i + (1 << 17)] = {a[i], b[i], c[i], max(0ll, a[i]), max(0ll, b[i]), max(0ll, c[i])};
	}
	s.build();

	while (q--) {
		int o;
		input(o);

		if (o == 1) {
			int l, r;
			input(l, r);
			s.upd(l - 1, r - 1, {1, 0, 2});
		}
		else if (o == 2) {
			int l, r;
			input(l, r);
			s.upd(l - 1, r - 1, {0, 2, 1});
		}
		else if (o == 3) {
			int l, r;
			input(l, r);
			s.upd(l - 1, r - 1, {2, 1, 0});
		}
		else {
			int i;
			input(i);
			int t = 0;
			int res = s.first(i - 1, t);
			print(res == -1 ? n + 1 : res + 1);
		}
	}
}
