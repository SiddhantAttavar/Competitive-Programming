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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int calc(string &t) {
	int k = count(all(t), '1'), n = sz(t);
	vi p(n + 1, 0);
	rep(i, 0, n) {
		p[i + 1] = p[i] + (t[i] == '1');
	}
	int res = n;
	rep(i, 0, n - k + 1) {
		res = min(res, k - (p[i + k] - p[i]));
	}
	return res;
}

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

bool check2(string s, int k, int x) {
	int n = sz(s);
	vi v(n, false);
	vi p(n + 1, 0);
	rep(i, 0, n) {
		if (s[i] == '?') {
			s[i] = '0';
			v[i] = true;
		}
		p[i + 1] = p[i] + (s[i] == '0');
	}

	LazySeg<int, int, 2048> lazy(1e18, 0, [](int a, int b) -> int {
		return min(a, b);
	}, [](int ind,int L,int R,vector<int>&seg,vector<int>&lazy) {
		/// modify values for current node
		seg[ind] += lazy[ind]; // dependent on operation
		if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
		lazy[ind] = 0; /// prop to children
	}); // recalc values for current node
	rep(i, 0, n - k + 1) {
		lazy.seg[i + 2048] = p[i + k] - p[i];
	}
	lazy.build();
	rep(i, 0, n) {
		if (v[i] and lazy.query(max(0ll, i - k + 1), i) > x) {
			lazy.upd(max(0ll, i - k + 1), i, -1);
			s[i] = '1';
		}
	}
	return lazy.query(0, n - k) >= x and count(all(s), '1') >= k;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s;
		input(s);

		int q = 0;
		rep(k, count(all(s), '1'), n + 1) {
			int l = 0, r = n;
			while (l <= r) {
				int m = (l + r) / 2;
				if (check2(s, k, m)) {
					q = max(q, m);
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
		}
		
		string u = s, v = s;
		rep(i, 0, n) {
			if (s[i] == '?') {
				u[i] = '0';
				v[i] = '1';
			}
		}
		print(min(calc(u), calc(v)), q);
	}
}
