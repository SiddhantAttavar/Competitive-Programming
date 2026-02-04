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

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string s, int lim=256) { // or vector<int>
		s.push_back(0); int n = sz(s), k = 0, a, b;
		vi x(all(s)), y(n), ws(max(n, lim));
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1ll, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
			for (k && k--, j = sa[x[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

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
	int get(int k, int i, int l = 0, int r = SZ - 1, int c = 1) {
		push(c, l, r, seg, lazy);
		if (l > i or k > seg[c]) {
			return -1;
		}
		if (l == r) {
			return l;
		}
		int m = (l + r) / 2;
		int x = get(k, i, m + 1, r, 2 * c + 1);
		if (x != -1) {
			return x;
		}
		return get(k - seg[2 * c + 1], i, l, m, 2 * c);
	}
};

int32_t main() {
	setup();

	string s;
	input(s);

	int k;
	input(k);

	int n = sz(s);
	k = n * (n + 1) / 2 + 1 - k;
	SuffixArray a(s);
	LazySeg<int, pii, 1 << 17> lazy(0, {0, -1}, [](int a, int b) {
		return a + b;
	}, [](int ind, int L, int R, vector<int> &seg, vector<pii> &lazy) {
		if (lazy[ind].second != -1) {
			seg[ind] = (R-L+1)*lazy[ind].second;
		}
		seg[ind] += (R-L+1)*lazy[ind].first; // dependent on operation
		if (L != R) {
			if (lazy[ind].second != -1) {
				lazy[2*ind] = lazy[ind];
				lazy[2*ind+1] = lazy[ind];
			}
			else {
				lazy[2*ind].first += lazy[ind].first;
				lazy[2*ind+1].first += lazy[ind].first;
			}
		}
		lazy[ind] = {0, -1}; /// prop to children
	});

	for (int i = n; i > 0; i--) {
		lazy.upd(1, n - a.sa[i], {1, -1});
		int j = lazy.get(k, n - a.sa[i]);
		if (j > a.lcp[i] and j <= n - a.sa[i]) {
			print(s.substr(a.sa[i], j));
			return 0;
		}
		k -= lazy.query(a.lcp[i] + 1, n - a.sa[i]);
		lazy.upd(a.lcp[i] + 1, n - a.sa[i], {0, 0});
	}
}
