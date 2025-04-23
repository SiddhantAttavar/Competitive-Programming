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
const int MOD = 998244353;

#define vi vector<int>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}

		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int mod_div(int a, int b) {
	return a * mod_pow(b, MOD - 2) % MOD;
}

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

template <typename T, typename U, bool VALS_EDGES, int SZ> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, rt, pos;
	LazySeg<T, U, SZ> tree;
	T ID; U ID2; T (*cmb)(T, T); void (*push)(int,int,int,T*,U*);
	HLD(vector<vi> adj_, T id, U id2, T _cmb(T, T), void _push(int,int,int,vector<T>&,vector<U>&))
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1),rt(N),
		pos(N),ID(id),cmb(_cmb),tree(id,id2,_cmb,_push){ dfsSz(0); dfsHld(0); }
	void dfsSz(int v) {
		for (int& u : adj[v]) {
			adj[u].erase(find(all(adj[u]), v));
			par[u] = v;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	template <class B> void process(int u, int v, B op) {
		for (;; v = par[rt[v]]) {
			if (pos[u] > pos[v]) swap(u, v);
			if (rt[u] == rt[v]) break;
			op(pos[rt[v]], pos[v]);
		}
		op(pos[u] + VALS_EDGES, pos[v]);
	}
	void modifyPath(int u, int v, int val) {
		process(u, v, [&](int l, int r) { tree.upd(l, r, val); });
	}
	T queryPath(int u, int v) { // Modify depending on problem
		T res = ID;
		process(u, v, [&](int l, int r) {res = cmb(res, tree.query(l, r));});
		return res;
	}
	T querySubtree(int v) { // modifySubtree is similar
		return tree.query(pos[v] + VALS_EDGES, pos[v] + siz[v] - 1);
	}
	void modifySubtree(int v, int x) { // modifySubtree is similar
		tree.upd(pos[v] + VALS_EDGES, pos[v] + siz[v] - 1, x);
	}
	int query(int u, vector<int> &a, vector<int> &s, vector<int> &t) {
		int res = 0, n = s.size();
		process(0, u, [&](int l, int r) {
			res = (res + tree.query(l, r)) % MOD;
			int u = t[l];
			if (par[u] != -1) {
				res = (res + a[par[u]] * mod_div(n - s[u], n)) % MOD;
			}
		});
		return res;
	}
};

void dfs(int u, int p, vector<vector<int>> &graph, vector<int> &s) {
	for (int v : graph[u]) {
		if (v != p) {
			dfs(v, u, graph, s);
			s[u] += s[v];
		}
	}
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	HLD<int, int, false, 1 << 18> h(graph, 0, 0, [](int a, int b) {
		return (a + b) % MOD;
	}, [](int ind,int L,int R,vector<int>&seg,vector<int>&lazy) {
		seg[ind] = (seg[ind] + (R - L + 1) * lazy[ind]) % MOD;
		if (L != R) {
			lazy[2 * ind] = (lazy[2 * ind] + lazy[ind]) % MOD;
			lazy[2 * ind + 1] = (lazy[2 * ind + 1] + lazy[ind]) % MOD;
		}
		lazy[ind] = 0;
	});

	vector<int> s(n, 1);
	dfs(0, -1, graph, s);

	vector<int> t(n);
	rep(i, 0, n) {
		t[h.pos[i]] = i;
	}

	int y = 0;
	vector<int> l(n, 0), p(n, 0);
	while (q--) {
		int o, u;
		input(o, u);
		u--;

		if (o == 2) {
			print((h.query(u, l, s, t) + y + l[u]) % MOD);
			continue;
		}

		int d;
		input(d);

		y = (y + d * mod_div(s[u], n)) % MOD;
		l[u] = (l[u] + d) % MOD;
		h.modifyPath(u, u, d * mod_div(MOD - s[u], n) % MOD);
		if (!h.adj[u].empty()) {
			int v = h.adj[u][0];
			h.modifyPath(v, v, d * mod_div(n - s[v], n) % MOD);
		}
	}
}
