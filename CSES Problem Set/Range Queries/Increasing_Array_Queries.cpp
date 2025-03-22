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
	const T ID1; const U ID2;
	vector<T> seg; vector<U> lazy;
	T (*cmb)(T a, T b);
	void (*push)(int,int,int,vector<T>&,vector<U>&) = 
		[&](int ind,int L,int R,vector<T>&_seg,vector<U>&_lazy) {
		/// modify values for current node
		seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
		if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
		lazy[ind] = ID2; /// prop to children
	}; // recalc values for current node
	LazySeg(T id1, U id2, T _cmb(T, T), void _push(int,int,int,vector<T>&,vector<U>&)):
		ID1(id1),ID2(id2),cmb(_cmb),push(_push),seg(2*SZ,id1),lazy(2*SZ,id2){}
	void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}
	void build() { for(int i=SZ-1;i>=1;i--) pull(i); }
	void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
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

LazySeg<int, int, 1 << 18> l(0, -1, [](int a, int b) {
	return a + b;
}, [](int i, int l, int r, vector<int> &seg, vector<int> &lazy) {
	if (lazy[i] != -1) {
		seg[i] = (r - l + 1) * lazy[i];
		if (l != r) {
			lazy[2 * i] = lazy[i];
			lazy[2 * i + 1] = lazy[i];
		}
		lazy[i] = -1;
	}
});

int32_t main() {
	setup();
	
	int n, q;
	input(n, q);

	vector<int> a(n);
	arrput(a);

	rep(i, 0, n) {
		l.seg[i + (1 << 18)] = a[i];
	}
	l.build();

	vector<vector<pair<int, int>>> v(n);
	rep(i, 0, q) {
		int l, r;
		input(l, r);

		v[l - 1].push_back({r - 1, i});
	}

	a.push_back(1e9 + 1);
	stack<int> s;
	s.push(n);

	vector<int> pref(n + 1, 0);
	rep(i, 0, n) {
		pref[i + 1] = pref[i] + a[i];
	}

	vector<int> res(q);
	for (int i = n - 1; i >= 0; i--) {
		while (a[i] >= a[s.top()]) {
			s.pop();
		}
		l.upd(i, s.top() - 1, a[i]);
		s.push(i);

		for (pair<int, int> p : v[i]) {
			res[p.second] = l.query(i, p.first) - pref[p.first + 1] + pref[i];
		}
	}
	for (int i : res) {
		print(i);
	}
}
