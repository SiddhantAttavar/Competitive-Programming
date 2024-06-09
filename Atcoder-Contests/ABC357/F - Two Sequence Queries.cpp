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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = 998244353;

using ll = long long;
using db = long double; // or double if tight TL
using str = string;

using pi = pair<int,int>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const db PI = acos((db)-1);
mt19937 rng(0); // or mt19937_64

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

// int main() { cin.tie(0)->sync_with_stdio(0); }

struct LazySeg { 
	struct F { // lazy update
		pair<int, int> inc = {0, 0};
		F() {}
		F(pair<int, int> x) { inc = x; }
		F& operator*=(const F& a) { inc = {(inc.first + a.inc.first) % MOD, (inc.second + a.inc.second) % MOD}; return *this; }
	}; V<F> lazy;
	struct T { // data you need to store for each interval
		ll sz = 1;
		vector<int> y = {0, 0, 0, 0};
		T() {}
		T(vector<int> x) { y = x; }
		friend T operator+(const T& a, const T& b) {
			vector<int> x = a.y, y = b.y;
			return T({(x[0] + y[0]) % MOD, (x[1] + y[1]) % MOD, (x[2] + y[2]) % MOD, x[3] + y[3]});
		}
		T& operator*=(const F& a) {
			y = {
				(y[0] + y[1] * a.inc.second + y[2] * a.inc.first + y[3] * ((a.inc.first * a.inc.second) % MOD)) % MOD,
				(y[1] + y[3] * a.inc.first) % MOD,
				(y[2] + y[3] * a.inc.second) % MOD,
				y[3]
			};
			return *this;
		}
	}; V<T> seg;
	int SZ = 1;
	void init(const V<T>& _seg) {
		while (SZ < (int) size(_seg)) SZ *= 2;
		seg.rsz(2*SZ); lazy.rsz(2*SZ);
		F0R(i,(int)_seg.size()) seg[SZ+i] = _seg[i];
		ROF(i,1,SZ) pull(i);
	}
	void push(int ind) { /// modify values for current node
		seg[ind] *= lazy[ind];
		if (ind < SZ) F0R(i,2) lazy[2*ind+i] *= lazy[ind];
		lazy[ind] = F();
	} // recalc values for current node
	void pull(int ind) { seg[ind] = seg[2*ind]+seg[2*ind+1]; }
	void upd(int lo, int hi, F inc, int ind, int L, int R) {
		push(ind); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	void upd(int lo, int hi, pair<int, int> inc) { upd(lo,hi,{inc},1,0,SZ-1); }
	T query(int lo, int hi, int ind, int L, int R) {
		push(ind); if (lo > R || L > hi) return T();
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; 
		return query(lo,hi,2*ind,L,M)+query(lo,hi,2*ind+1,M+1,R);
	}
	T query(int lo, int hi) { return query(lo,hi,1,0,SZ-1); }
};

const int N = 2e5;

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<int> a(n), b(n);
	arrPut(a);
	arrPut(b);

	vector<LazySeg::T> c(n);
	range(i, 0, n) {
		c[i] = LazySeg::T({(a[i] * b[i]) % MOD, a[i] % MOD, b[i] % MOD, 1});
	}

	LazySeg s;
	s.init(c);

	while (q--) {
		int o, l, r;
		input(o, l, r);

		l--;
		r--;

		if (o == 1) {
			int x;
			input(x);
			s.upd(l, r, {x % MOD, 0});
		}
		else if (o == 2) {
			int x;
			input(x);
			s.upd(l, r, {0, x % MOD});
		}
		else {
			print(s.query(l, r).y[0]);
		}
	}
}
