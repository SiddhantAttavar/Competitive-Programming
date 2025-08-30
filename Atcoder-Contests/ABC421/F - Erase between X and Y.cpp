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
};

LazySeg<int, int, 1 << 19> l(0, 0, [](int a, int b) {
	return  a + b;
}, [](int ind,int L,int R,vector<int>&seg,vector<int>&lazy) {
	/// modify values for current node
	seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
	if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
	lazy[ind] = 0; /// prop to children
});

pair<int, pair<int, int>> lca(int u, int v, vector<vector<int>> &par, vector<int> &l) {
	if (l[u] > l[v]) {
		swap(u, v);
	}

	for (int i = 19; i >= 0; i--) {
		if (l[v] - (1 << i) >= l[u]) {
			v = par[v][i];
		}
	}

	if (u == v) {
		return {u, {-1, -1}};
	}

	for (int i = 19; i >= 0; i--) {
		if (par[u][i] != par[v][i]) {
			v = par[v][i];
			u = par[u][i];
		}
	}
	return {par[u][0], {u, v}};
}

int32_t main() {
	setup();

	int q;
	input(q);

	const int N = 5e5 + 1, H = 20;
	vector<int> next(N), l(N, 0);
	vector<vector<int>> par(N, vector<int>(H, -1));
	next[0] = 1e9;
	rep(i, 1, q + 1) {
		int o;
		input(o);

		if (o == 1) {
			int x;
			input(x);

			int y = next[x];
			next[x] = i;
			next[i] = y;

			par[i][0] = x;
			l[i] = l[x] + 1;
			rep(j, 1, 20) {
				if (par[i][j - 1] == -1) {
					break;
				}
				par[i][j] = par[par[i][j - 1]][j - 1];
			}
		}
		else {
			int x, y;
			input(x, y);

			pair<int, pair<int, int>> v = lca(x, y, par, l);
			if (v.first == y) {
				swap(x, y);
			}
			else if (v.first != x and v.second.first > v.second.second) {
				swap(x, y);
			}

			int u = next[x], res = 0;
			while (u != y and u != 1e9) {
				res += u;
				u = next[u];
			}
			next[x] = y;
			print(res);
		}
	}
}
