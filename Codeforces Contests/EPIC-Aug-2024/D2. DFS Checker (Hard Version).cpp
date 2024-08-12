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
const int MOD = (int) 1e9 + 7;

void dfs(int u, vector<vector<int>> &graph, vector<int> &s, vector<int> &l) {
	for (int v : graph[u]) {
		l[v] = l[u] + 1;
		dfs(v, graph, s, l);
		s[u] += s[v];
	}
}

vector<int> segTree, l;
vector<vector<int>> graph, par;

int lca(int u, int v) {
	if (u == -1) {
		return v;
	}
	if (v == -1) {
		return u;
	}

	if (l[u] > l[v]) {
		swap(u, v);
	}

	for (int i = 29; i >= 0; i--) {
		if (l[v] >= (1 << i) + l[u]) {
			v = par[v][i];
		}
	}
	return u;

	if (u == v) {
		return u;
	}

	for (int i = 29; i >= 0; i--) {
		if (par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}

	return par[u][0];
}

void update(int c, int l, int r, int i, int x) {
	if (l == r) {
		segTree[c] = x;
		return;
	}

	int m = (l + r) / 2;
	if (i <= m) {
		update(2 * c, l, m, i, x);
	}
	else {
		update(2 * c + 1, m + 1, r, i, x);
	}
	segTree[c] = lca(segTree[2 * c], segTree[2 * c + 1]);
}

int query(int c, int l, int r, int s, int e) {
	if (e < l or r < s) {
		return -1;
	}
	if (s <= l and r <= e) {
		return segTree[c];
	}
	
	int m = (l + r) / 2;
	return lca(
		query(2 * c, l, m, s, e),
		query(2 * c + 1, m + 1, r, s, e)
	);
}

template<class T, int SZ> struct LazySeg { 
	const T ID = true; T cmb(T a, T b) {return a & b;};
	T seg[2*SZ], lazy[2*SZ]; 
	LazySeg() { range(i,0, 2*SZ) {seg[i] = true; lazy[i] = false;} }
	void push(int ind, int L, int R) { /// modify values for current node
		seg[ind] |= lazy[ind]; // dependent on operation
		if (L != R) range(i,0,2) lazy[2*ind+i] = lazy[ind]; /// prop to children
		lazy[ind] = false;
	} // recalc values for current node
	void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}
	void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }

		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R); if (lo > R || L > hi) return ID;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
			query(lo,hi,2*ind+1,M+1,R));
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vector<vector<int>> graph(n);
		par = vector<vector<int>>(n, vector<int>(30, -1));
		range(i, 1, n) {
			input(par[i][0]);
			par[i][0]--;
			graph[par[i][0]].push_back(i);
		}

		range(i, 0, n) {
			range(j, 1, 30) {
				if (par[i][j - 1] == -1) {
					break;
				}
				par[i][j] = par[par[i][j - 1]][j - 1];
			}
		}

		vector<int> p(n);
		arrPut(p);

		vector<int> s(n, 1);
		l.clear();
		l.resize(n, 0);
		dfs(0, graph, s, l);

		vector<int> m(n);
		segTree.clear();
		segTree.resize(4 * n, 0);
		range(i, 0, n) {
			p[i]--;
			m[p[i]] = i;
			update(1, 0, n - 1, i, p[i]);
		}

		LazySeg<bool, 1ll> res;
		range(i, 0, n) {
			if (p[i] == 0) {
				res.upd(i, i, i == 0);
			}
			else {
				res.upd(i, i, m[p[i]] >= m[par[p[i]][0]] and m[par[p[i]][0]] + s[par[p[i]][0]] > m[p[i]]);
			}
		}

		while (q--) {
			int x, y;
			input(x, y);
			x--;
			y--;

			swap(p[x], p[y]);
			update(1, 0, n - 1, x, p[x]);
			update(1, 0, n - 1, y, p[y]);

			res.upd(x, x, true);
			res.upd(y, y, true);

			if (p[x] == 0) {
				res.upd(x, x, x == 0);
			}
			else {
				res.upd(x, x, m[p[x]] >= m[par[p[x]][0]] and m[par[p[x]][0]] + s[par[p[x]][0]] > m[p[x]]);
			}
			if (p[y] == 0) {
				res.upd(y, y, y == 0);
			}
			else {
				res.upd(y, y, m[p[y]] >= m[par[p[y]][0]] and m[par[p[y]][0]] + s[par[p[y]][0]] > m[p[y]]);
			}

			if (x + s[p[x]] <= n and query(1, 0, n - 1, x, x + s[p[x]] - 1) == p[x]) {
				res.upd(x + 1, x + s[p[x]] - 1, true);
			}
			if (y + s[p[y]] <= n and query(1, 0, n - 1, y, y + s[p[y]] - 1) == p[y]) {
				res.upd(y + 1, y + s[p[y]] - 1, true);
			}

			if (res.query(0, n - 1)) {
				print("YES");
			}
			else {
				print("NO");
			}
		}
	}
}
