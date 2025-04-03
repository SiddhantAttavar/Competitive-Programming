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

int seg[1 << 22];
pair<int, int> lazy[1 << 22];
template<class T, class U, int SZ> struct LazySeg { 
	// static_assert(pct(SZ) == 1); // SZ must be power of 2
	const T ID1;
	T (*cmb)(T a, T b);
	void (*push)(int,int,int) = 
		[&](int ind,int L,int R) {
		/// modify values for current node
		// seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
		// if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
		// lazy[ind] = 0; /// prop to children
	}; // recalc values for current node
	LazySeg(T id1, U id2, T _cmb(T, T), void _push(int,int,int)):
		ID1(id1),cmb(_cmb),push(_push){
			fill(lazy, lazy + (1 << 20), id2);
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

LazySeg<int, pair<int, int>, 1 << 21> s(0, {-1, 1e18}, [](int a, int b) {
	return a + b;
}, [](int i, int l, int r) {
	seg[i] = max(seg[i], lazy[i].first);
	seg[i] = min(seg[i], lazy[i].second);
	if (l == r) {
		lazy[i] = {-1, 1e18}; /// prop to children
		return;
	}

	lazy[2 * i].first = max(lazy[2 * i].first, lazy[i].first);
	lazy[2 * i].second = max(lazy[2 * i].second, lazy[2 * i].first);
	lazy[2 * i + 1].first = max(lazy[2 * i + 1].first, lazy[i].first);
	lazy[2 * i + 1].second = max(lazy[2 * i + 1].second, lazy[2 * i + 1].first);
	lazy[2 * i].second = min(lazy[2 * i].second, lazy[i].second);
	lazy[2 * i].first = min(lazy[2 * i].first, lazy[2 * i].second);
	lazy[2 * i + 1].second = min(lazy[2 * i + 1].second, lazy[i].second);
	lazy[2 * i + 1].first = min(lazy[2 * i + 1].first, lazy[2 * i + 1].second);
	lazy[i] = {-1, 1e18}; /// prop to children
});

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	while (q--) {
		int o, l, r, h;
		input(o, l, r, h);

		if (o == 1) {
			s.upd(l, r, {h, 1e18});
		}
		else {
			s.upd(l, r, {-1, h});
		}
	}

	rep(i, 0, n) {
		print(s.query(i, i));
	}
}
