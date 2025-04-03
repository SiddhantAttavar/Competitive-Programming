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

template<class T, class U, int SZ> struct LazySeg { 
	// static_assert(pct(SZ) == 1); // SZ must be power of 2
	const T ID1;
	vector<T> seg; vector<U> lazy;
	T (*cmb)(T a, T b);
	void (*push)(int,int,int,vector<T>&,vector<U>&) = 
		[&](int ind,int L,int R,vector<T>&_seg,vector<U>&_lazy) {
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
			lazy[ind] = {inc.first + inc.second * (L-lo), inc.second}; push(ind,L,R,seg,lazy); return; }
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

LazySeg<int, pair<int, int>, 1 << 18> s(0, {0, 0}, [](int a, int b) {
	return a + b;
}, [](int ind, int L, int R, vector<int> &seg, vector<pair<int, int>> &lazy) {
	seg[ind] += ((R-L+1) * (2 * lazy[ind].first + (R-L)*lazy[ind].second)) / 2; // dependent on operation
	if (L != R) {
		int M = (L + R) / 2;
		lazy[2*ind].first += lazy[ind].first;
		lazy[2*ind].second += lazy[ind].second;
		lazy[2*ind+1].first += lazy[ind].first + lazy[ind].second * (M+1-L);
		lazy[2*ind+1].second += lazy[ind].second;
	}
	lazy[ind] = {0, 0}; /// prop to children
});

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	while (q--) {
		int o;
		input(o);

		if (o == 1) {
			int l, r, a, d;
			input(l, r, a, d);
			s.upd(l - 1, r - 1, {a, d});
		}
		else {
			int i;
			input(i);
			print(s.query(i - 1, i - 1));
		}
	}
}
