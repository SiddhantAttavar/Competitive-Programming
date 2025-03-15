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

template<class T, int SZ> struct LazySeg { 
	T seg[2*SZ], lazy[2*SZ]; 
	// static_assert(pct(SZ) == 1); // SZ must be power of 2
	const T ID = 0; T cmb(T a, T b) {return max(a, b);};
	LazySeg() { rep(i,0,2*SZ) seg[i] = lazy[i] = ID; }
	void push(int ind, int L, int R) { /// modify values for current node
		seg[ind] += lazy[ind]; // dependent on operation
		if (L != R) rep(i,0,2) lazy[2*ind+i] += lazy[ind]; /// prop to children
		lazy[ind] = 0; 
	} // recalc values for current node
	void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}
	void build() { for(int i=SZ-1;i>=1;i--) pull(i); }
	void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R); if (lo > R || L > hi) return ID;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
			query(lo,hi,2*ind+1,M+1,R));
	}
};

const int N = 1 << 19;
LazySeg<int, N> s;

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> a(n);
	arrput(a);

	vector<int> v(n + 1, -1);
	set<int> m;
	vector<int> dp(n);
	rep(i, 0, n) {
		s.upd(i, i, m.size());
		m.insert(a[i]);
		s.upd(v[a[i]] + 1, i, 1);
		v[a[i]] = i;
		dp[i] = s.query(0, i);
	}

	m.clear();
	int res = 0;
	for (int i = n - 1; i >= 2; i--) {
		m.insert(a[i]);
		res = max(res, (int) (dp[i - 1] + m.size()));
	}
	print(res);
}
