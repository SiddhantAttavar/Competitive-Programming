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
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

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

void dfs(int u, vector<vector<pii>> &tree, vi &d, vi &a, vi &b, vi &l) {
	a[u] = sz(l);
	l.push_back(u);
	for (auto [v, w] : tree[u]) {
		d[v] = d[u] + w;
		dfs(v, tree, d, a, b, l);
	}
	b[u] = sz(l) - 1;
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<array<int, 3>> e(2 * (n - 1));
	rep(i, 0, 2 * (n - 1)) {
		int a, b, c;
		input(a, b, c);
		e[i] = {a - 1, b - 1, c};
	}

	vi x(n, 0);
	vector<vector<pii>> tree(n);
	rep(i, 0, n - 1) {
		tree[e[i][0]].push_back({e[i][1], e[i][2]});
		x[e[i + n - 1][0]] = e[i + n - 1][2];
	}

	vi d(n, 0), a(n), b(n), l;
	dfs(0, tree, d, a, b, l);

	LazySeg<int, int, 1 << 18> s(1e18, 0, [](int a, int b) {
		return min(a, b);
	}, [](int ind, int L, int R, vi &seg, vi &lazy) {
		/// modify values for current node
		seg[ind] += lazy[ind]; // dependent on operation
		if (L != R) {
			lazy[2*ind] += lazy[ind];
			lazy[2*ind+1] += lazy[ind];
		}
		lazy[ind] = 0; /// prop to children
	});

	rep(i, 0, n) {
		s.seg[i + (1 << 18)] = x[l[i]] + d[l[i]];
	}
	s.build();

	while (q--) {
		int o;
		input(o);

		if (o == 1) {
			int i, w;
			input(i, w);

			i--;
			if (i < n - 1) {
				int v = e[i][1];
				s.upd(a[v], b[v], w - e[i][2]);
				e[i][2] = w;
			}
			else {
				int u = e[i][0];
				s.upd(a[u], a[u], w - x[u]);
				x[u] = w;
			}
		}
		else {
			int u, v;
			input(u, v);

			u--;
			v--;

			int res = (s.query(a[v], a[v]) - x[v]) - (s.query(a[u], a[u]) - x[u]);
			if (a[u] > a[v] or b[v] > b[u]) {
				res += s.query(a[u], b[u]);
			}
			print(res);
		}
	}
}
