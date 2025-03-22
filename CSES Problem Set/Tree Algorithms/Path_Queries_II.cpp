#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
// #define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;
 
#define vi vector<int>
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
 
template<typename T> struct SegTree { // cmb(ID,b) = b
	T ID; T (*cmb)(T a, T b);
	int n; vector<T> seg;
	SegTree(int _n, T id, T _cmb(T, T)) {
		ID = id; cmb = _cmb;
		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,ID); 
	}
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
};
 
template <typename T, bool VALS_EDGES, int SZ> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, rt, pos;
	SegTree<T> tree;
	T ID; T (*cmb)(T, T);
	HLD(vector<vi> adj_, T id, T _cmb(T, T))
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1),
		  rt(N),pos(N),ID(id),cmb(_cmb),tree(N, id, _cmb){ dfsSz(0); dfsHld(0); }
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
	void modify(int u, int val) {
		tree.upd(pos[u], val);
	}
	T queryPath(int u, int v) { // Modify depending on problem
		T res = ID;
		process(u, v, [&](int l, int r) {
				res = cmb(res, tree.query(l, r));
		});
		return res;
	}
	T querySubtree(int v) { // modifySubtree is similar
		return tree.query(pos[v] + VALS_EDGES, pos[v] + siz[v] - 1);
	}
};
 
signed main() {
	setup();
 
	int n, q;
	input(n, q);
 
	vector<int> v(n);
	arrput(v);
 
	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);
 
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}
 
	HLD<int, false, 1 << 18> h(graph, 0, [](int x, int y) {
		return max(x, y);
	});
 
	rep(i, 0, n) {
		h.modify(i, v[i]);
	}
 
	while (q--) {
		int o, x, y;
		input(o, x, y);
 
		if (o == 1) {
			h.modify(x - 1, y);
		}
		else {
			cout << h.queryPath(x - 1, y - 1) <<  ' ';
		}
	}
}
