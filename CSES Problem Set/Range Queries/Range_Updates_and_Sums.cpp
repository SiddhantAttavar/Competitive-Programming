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
	// static_assert(pct(SZ) == 1); // SZ must be power of 2
	const T ID; T (*cmb)(T a, T b);
	T seg[2*SZ];
	pair<T, T> lazy[2*SZ];
	LazySeg(T id, T _cmb(T, T)):ID(id),cmb(_cmb) { rep(i,0,2*SZ) {seg[i] = ID; lazy[i] = {-1, ID};} }
	void push(int ind, int L, int R) { /// modify values for current node
		if (lazy[ind].first != -1) {
			seg[ind] = (R-L+1)*lazy[ind].first;
		}
		seg[ind] += (R-L+1)*lazy[ind].second;
		if (L != R) {
			if (lazy[ind].first != -1) {
				lazy[2*ind].first = lazy[ind].first;
				lazy[2*ind+1].first = lazy[ind].first;
				lazy[2*ind].second = 0;
				lazy[2*ind+1].second = 0;
			}
			lazy[2*ind].second += lazy[ind].second;
			lazy[2*ind+1].second += lazy[ind].second;
		}
		lazy[ind] = {-1, ID};
	} // recalc values for current node
	void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}
	void build() { for(int i=SZ-1;i>=1;i--) pull(i); }
	void upd(int lo,int hi,T inc, bool b, int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			if (b) {
				lazy[ind].second += inc;
			}
			else {
				lazy[ind].first = inc;
				lazy[ind].second = 0;
			}
			push(ind,L,R);
			return;}
		int M = (L+R)/2; upd(lo,hi,inc,b,2*ind,L,M); 
		upd(lo,hi,inc,b,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R); if (lo > R || L > hi) return ID;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
			query(lo,hi,2*ind+1,M+1,R));
	}
};


LazySeg<int, 1 << 18> l(0, [](int a, int b) {
	return a + b;
});
int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<int> a(n);
	arrput(a);

	rep(i, 0, n) {
		l.seg[i+(1 << 18)] = a[i];
	}
	l.build();

	while (q--) {
		int o;
		input(o);
		int a, b;
		input(a, b);
		a--;
		b--;

		if (o == 1) {
			int x;
			input(x);
			l.upd(a, b, x, true);
		}
		else if (o == 2) {
			int x;
			input(x);
			l.upd(a, b, x, false);
		}
		else {
			print(l.query(a, b));
		}
	}
}
