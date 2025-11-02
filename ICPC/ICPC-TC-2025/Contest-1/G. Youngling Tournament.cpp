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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

template<class T, class U, int SZ> struct LazySeg { 
	// static_assert(pct(SZ) == 1); // SZ must be power of 2
	const T ID1;
	vector<T> seg; vector<U> lazy;
	T (*cmb)(T a, T b);
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
	int find_next(int lo, int ind=1, int L=0, int R=SZ-1) {
		push(ind, L, R, seg, lazy);
		if (R < lo or seg[ind] < 0) {
			return -1;
		}
		if (L == R) {
			return L;
		}
		int M = (L + R) / 2;
		int res = find_next(lo, 2 * ind, L, M);
		if (res == -1) {
			return find_next(lo, 2 * ind + 1, M + 1, R);
		}
		return res;
	}
};

const int N = 1 << 18;
LazySeg<int, int, N> seg(-1e18, 0, [](int a, int b) {
	return max(a, b);
}, [](int ind,int L,int R,vector<int>&seg,vector<int>&lazy) {
	/// modify values for current node
	seg[ind] += lazy[ind]; // dependent on operation
	if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
	lazy[ind] = 0; /// prop to children
});

int32_t main() {
	setup();

	int n;
	input(n);

	vector<tuple<int, int, int>> a(n, {0, 0, -1});
	rep(i, 0, n) {
		int x;
		input(x);
		a[i] = {x, i, -1};
	}

	int m;
	input(m);
	rep(i, 0, m) {
		int j, x;
		input(j, x);
		a.push_back({x, j - 1, i});
	}
	sort(a.begin(), a.end());

	vector<pair<int, int>> p(n);
	vector<int> f(n + m, -1);
	vector<tuple<int, int, int>> l(m);
	int c = 0;
	for (auto [x, i, t] : a) {
		if (t == -1) {
			f[c] = x;
			p[i] = {x, c};
		}
		else {
			l[t] = {x, i, c};
		}
		c++;
	}

	int z = 0;
	rep(i, 0, n + m) {
		seg.seg[i + N] = f[i] - z;
		z += max(0ll, f[i]);
	}
	seg.build();

	int k = -1, res = -1;
	do {
		k = seg.find_next(k + 1);
		res++;
	} while (k != -1);
	print(res);

	for (auto [y, i, v] : l) {
		auto [x, u] = p[i];
		seg.upd(u, u, -x - 1);
		seg.upd(u + 1, N - 1, x);
		seg.upd(v, v, y + 1);
		seg.upd(v + 1, N - 1, -y);
		p[i] = {y, v};

		int k = -1, res = -1;
		do {
			k = seg.find_next(k + 1);
			res++;
		} while (k != -1);
		print(res);
	}
}
