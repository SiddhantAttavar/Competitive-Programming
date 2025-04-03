#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

array<int, 4> seg[1 << 21];
int lazy[1 << 21];
template<class T, class U, int SZ> struct LazySeg { 
	// static_assert(pct(SZ) == 1); // SZ must be power of 2
	const T ID1;
	T (*cmb)(T a, T b);
	void (*push)(int,int,int) = 
		[&](int ind,int L,int R) {
		/// modify values for current node
		// seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
		if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
		lazy[ind] = 0; /// prop to children
	}; // recalc values for current node
	LazySeg(T id1, U id2, T _cmb(T, T), void _push(int,int,int)):
		ID1(id1),cmb(_cmb),push(_push){
			fill(lazy, lazy + (1 << 20), -1);
		}
	void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}
	void build() { for(int i=SZ-1;i>=1;i--) pull(i); }
	void upd(int lo,int hi,U inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R); if (lo > R || L > hi) return ID1;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
			query(lo,hi,2*ind+1,M+1,R));
	}
};

LazySeg<array<int, 4>, int, 1 << 20> s({-1, -1, -1, -1}, -1, [](array<int, 4> a, array<int, 4> b) {
	if (a[0] == -1) return b;
	if (b[0] == -1) return a;
	return array<int, 4>{
		a[0] + b[0],
		a[1] + b[1] - (a[3] & b[2]),
		a[2],
		b[3]
	};
}, [](int ind, int L, int R) {
	if (lazy[ind] == -1) return;
	seg[ind] = {(R-L+1)*lazy[ind], lazy[ind], lazy[ind], lazy[ind]};
	if (L != R) {
		lazy[2*ind] = lazy[ind];
		lazy[2*ind+1] = lazy[ind];
	}
	lazy[ind] = -1; /// prop to children
});

int32_t main() {
	setup();

	int q;
	input(q);

	while (q--) {
		char c;
		input(c);

		int x, l;
		input(x, l);

		s.upd(x + (1 << 19), x + l - 1 + (1 << 19), c == 'B');
		array<int, 4> v = s.query(0, (1 << 20) - 1);
		print(v[1], v[0]);
	}
}
