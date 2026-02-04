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
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

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

// a - (b - x) = a - b + x
// a + (b - x) = a + b - x

int32_t main() {
	setup();

	LazySeg<int, pii, 1 << 18> l(0, {0, 0}, [](int a, int b) {
		return a + b;
	}, [](int ind, int L, int R, vector<int> &seg, vector<pii> &lazy) {
		seg[ind] = lazy[ind].first + (lazy[ind].second ? -seg[ind] : seg[ind]);
		if (L != R) {
			lazy[2*ind].first = lazy[ind].first + (lazy[ind].second ? -lazy[2*ind].first : lazy[2*ind].first);
			lazy[2*ind].second ^= lazy[ind].second;
			lazy[2*ind+1].first = lazy[ind].first + (lazy[ind].second ? -lazy[2*ind+1].first : lazy[2*ind+1].first);
			lazy[2*ind+1].second ^= lazy[ind].second;
		}
		lazy[ind] = {0, 0}; /// prop to children
	});

	int n, m;
	input(n, m);
	rep(i, 0, n) {
		l.seg[i + (1 << 18)] = i;
	}

	string s;
	input(s);

	while (m--) {
		int a, b;
		input(a, b);
		a--;
		b--;
		l.upd(a, b, {a + b, 1});

		rep(i, 0, n) {
			cout << l.query(i, i) << ' ';
		}
		cout << endl;
	}

	string res(n, '-');
	rep(i, 0, n) {
		res[l.query(i, i)] = s[i];
	}
	print(res);
}
