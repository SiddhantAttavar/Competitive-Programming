#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T, class U> struct LazySeg { 
	// static_assert(pct(SZ) == 1); // SZ must be power of 2
	const T ID1; T (*cmb)(T a, T b);
	vector<T> seg; vector<U> lazy;
    int SZ = 1;
	void (*push)(int,int,int,vector<T>&,vector<U>&) = 
		[&](int ind,int L,int R,vector<T>&seg,vector<U>&lazy) {
		/// modify values for current node
		seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
		if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
		lazy[ind] = 0; /// prop to children
	}; // recalc values for current node
	LazySeg(int n, T id1, U id2, T _cmb(T, T), void _push(int,int,int,vector<T>&,vector<U>&)):
		ID1(id1),cmb(_cmb),push(_push){
            for (SZ = 1; SZ < n; ) SZ *= 2;
            seg.assign(2 * SZ, id1);
            lazy.assign(2 * SZ, id2);
        }
	void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}
	void build() { for(int i=SZ-1;i>=1;i--) pull(i); }
	void upd(int lo,int hi,U inc,int ind=1,int L=0, int R=-1) {
        if (R == -1) {upd(lo, hi, inc, 1, 0, SZ - 1); return;}
		push(ind,L,R,seg,lazy); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R,seg,lazy); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=-1) {
        if (R == -1) return query(lo, hi, 1, 0, SZ - 1);
		push(ind,L,R,seg,lazy); if (lo > R || L > hi) return ID1;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
			query(lo,hi,2*ind+1,M+1,R));
	}
};

template <typename T, typename U, bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, rt, pos;
	LazySeg<T, U> tree;
	T ID; U ID2; T (*cmb)(T, T); void (*push)(int,int,int,T*,U*);
	HLD(vector<vi> adj_, T id, U id2, T _cmb(T, T), void _push(int,int,int,vector<T>&,vector<U>&))
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1),rt(N),
		pos(N),ID(id),cmb(_cmb),tree(N,id,id2,_cmb,_push){ dfsSz(0); dfsHld(0); }
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
	void modifyPath(int u, int v, U val) {
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
    T modifySubtree(int v, U val) { // modifySubtree is similar
		return tree.upd(pos[v] + VALS_EDGES, pos[v] + siz[v] - 1, val);
	}
};

void solve() {
	int n;
    cin >> n;

    vector<vi> graph(n);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    
    HLD<pii, int, false> h(graph, {0, 0}, 0, [](pii a, pii b) -> pii {
        if (a.first == b.first) {
            return {a.first, a.second + b.second};
        }
        return max(a, b);
    }, [](int ind,int L,int R,vector<pii>&seg,vector<int>&lazy) {
        /// modify values for current node
		seg[ind].first += lazy[ind]; // dependent on operation
		if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
		lazy[ind] = 0; /// prop to children
	});
    rep(i, 0, n) {
        h.tree.seg[h.tree.SZ + h.pos[i]] = {0, 1};
    }
    h.tree.build();

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;

        vector<pii> l(k);
        rep(i, 0, k) {
            int u, v;
            cin >> u >> v;
            l[i] = {u - 1, v - 1};
        }

        for (auto [u, v] : l) {
            h.modifyPath(u, v, 1);
        }

        auto [x, y] = h.querySubtree(0);
        if (x < k) {
            cout << 0 << endl;
        }
        else {
            cout << y << endl;
        }

        for (auto [u, v] : l) {
            h.modifyPath(u, v, -1);
        }
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	rep(i, 0, t) {
        cout << "Case " << i + 1 << ":\n";
        solve();
    }
}
