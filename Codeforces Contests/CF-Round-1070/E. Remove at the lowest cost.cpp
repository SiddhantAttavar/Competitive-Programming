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

template<class T, class U> struct LazySeg { 
	// static_assert(pct(SZ) == 1); // SZ must be power of 2
	int SZ;	const T ID1; T (*cmb)(T a, T b);
	vector<T> seg; vector<U> lazy;
	void (*push)(int,int,int,vector<T>&,vector<U>&) = 
		[&](int ind,int L,int R,vector<T>&seg,vector<U>&lazy) {
		/// modify values for current node
		seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
		if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
		lazy[ind] = 0; /// prop to children
	}; // recalc values for current node
	LazySeg(int _SZ, T id1, U id2, T _cmb(T, T), void _push(int,int,int,vector<T>&,vector<U>&)):
		ID1(id1),cmb(_cmb),push(_push),seg(4*_SZ,id1),lazy(4*_SZ,id2){
			SZ = 1; while (SZ < _SZ) SZ *= 2;
		}
	void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}
	void build() { for(int i=SZ-1;i>=1;i--) pull(i); }
	void upd(int lo,int hi,U inc,int ind=1,int L=0, int R=-1) {
		if (R == -1) {upd(lo, hi, inc, 1, 0, SZ-1); return;}
		push(ind,L,R,seg,lazy); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R,seg,lazy); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=-1) {
		if (R == -1) return query(lo, hi, 1, 0, SZ-1);
		push(ind,L,R,seg,lazy); if (lo > R || L > hi) return ID1;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
			query(lo,hi,2*ind+1,M+1,R));
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n), c(n), p(n);
		arrput(a);
		arrput(c);
		arrput(p);

		vector<int> l(n, 0), r(n, n - 1);
		stack<int> s;
		rep(i, 0, n) {
			while (!s.empty() and a[s.top()] <= a[i]) {
				s.pop();
			}
			if (!s.empty()) {
				l[i] = s.top() + 1;
			}
			s.push(i);
		}
		while (!s.empty()) {
			s.pop();
		}
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() and a[s.top()] <= a[i]) {
				s.pop();
			}
			if (!s.empty()) {
				r[i] = s.top() - 1;
			}
			s.push(i);
		}

		vector<vector<int>> x(n), y(n);
		rep(i, 0, n) {
			x[l[i]].push_back(c[i]);
			y[r[i]].push_back(c[i]);
		}

		LazySeg<pair<int, int>, bool> lazy(n, {0, 0}, false, [](pair<int, int> a, pair<int, int> b) -> pair<int, int> {
			return {a.first + b.first, max(a.second, b.second)};
		}, [](int i, int l, int r, vector<pair<int, int>> &seg, vector<bool> &lazy) {
			if (!lazy[i]) return;
			seg[i] = {0, 0};
			if (l != r) {lazy[2*i] = true; lazy[2*i+1] = true;}
		});

		multiset<int> m;
		rep(i, 0, n) {
			for (int c : x[i]) {
				m.insert(c);
			}
			lazy.seg[lazy.SZ + i] = {*m.begin(), *m.begin()};
			for (int c : y[i]) {
				m.erase(m.find(c));
			}
		}
		lazy.build();

		auto [u, v] = lazy.query(0, n - 1);
		cout << u - v;
		for (int i : p) {
			lazy.upd(l[i - 1], r[i - 1], true);
			auto [u, v] = lazy.query(0, n - 1);
			cout << ' ' << u - v;
		}
		cout << endl;
	}
}
