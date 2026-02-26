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
 
#define ll long long
 
struct Centroid { // 0 based indexing.
	vector<vi> centroid_tree, adj;
	vi par_ct, siz;
	vector<bool> vis;
	Centroid(vector<vector<ll>> _adj) : adj(_adj), centroid_tree(sz(_adj)),
		siz(sz(_adj)), vis(sz(_adj)), par_ct(sz(_adj), -1) {}
	void find_size(ll v, ll par) {
		siz[v] = 1;
		for(auto x : adj[v]) {
			if(x == par || vis[x]) continue;
			find_size(x, v);
			siz[v] += siz[x];
		}
	}
	ll find_centroid(ll v, ll par, ll n_nodes) {
		for(auto x : adj[v]) {
			if(x == par || vis[x]) continue;
			if(siz[x] > n_nodes/2) return find_centroid(x, v, n_nodes); 
		}
		return v;
	}
	void process(ll v) {} // optional
	ll solve(ll v, ll prev) {
		find_size(v, prev);
		ll centroid = find_centroid(v, prev, siz[v]);
		vis[centroid] = true;
		par_ct[centroid] = prev;
		process(centroid);
		for(auto x : adj[centroid]) { 
			if (vis[x]) continue;
			centroid_tree[centroid].push_back(solve(x, centroid));
		}
		return centroid;
	}
};
 
int dfs(int u, int p, vector<vi> &graph, vi &s, vi &pow2) {
	vector<pii> l;
	for (int v : graph[u]) {
		if (v != p) {
			l.push_back({dfs(v, u, graph, s, pow2), s[v]});
			s[u] += s[v];
		}
	}
	sort(all(l));
	int res = 0;
	for (auto [x, s] : l) {
		res = (res * pow2[2 * s] + x) % MOD;
	}
	res = (res * 2 + 1) % MOD;
	return res;
}
 
vi get(vector<vi> &graph) {
	Centroid c(graph);
	c.find_size(0, -1);
	int v = c.find_centroid(0, -1, sz(graph));
	c.vis[v] = true;
	c.find_size(v, -1);
	for (int u : graph[v]) {
		if (sz(graph) % 2 == 0 and c.siz[u] == sz(graph) / 2) {
			return {v, u};
		}
	}
	return {v};
}

const int N = 2e5;
vi pow2(N + 1, 1);

bool check(vector<vi> &g1, vector<vi> &g2) {
	int n = sz(g1);
	for (int i : get(g1)) {
		for (int j : get(g2)) {
			vi s1(n, 1), s2(n, 1);
			if (dfs(i, -1, g1, s1, pow2) == dfs(j, -1, g2, s2, pow2)) {
				return true;
			}
		}
	}
	return false;
}

int mpow(int a, int b) {
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

int mdiv(int a, int b) {
	return a * mpow(b, MOD - 2) % MOD;
}

int32_t main() {
	rep(i, 1, N + 1) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vi> tree(n);
		vi d(n, 0);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);
			u--;
			v--;
			tree[u].push_back(v);
			tree[v].push_back(u);
			d[u]++;
			d[v]++;
		}
		rep(i, 0, n) {
			sort(all(tree[i]));
		}
		vi nd = d;
		sort(all(nd));

		vector<vi> l = {{-1}};
		rep(i, 1, n) {
			vector<vi> nl;
			for (vi &v : l) {
				rep(p, 0, i) {
					vi w = v;
					w.push_back(p);
					nl.push_back(w);
				}
			}
			l = nl;
		}

		int res = 0;
		for (vi &p : l) {
			vi x(n, 0);
			vector<vi> adj(n);
			rep(i, 1, n) {
				x[p[i]]++;
				x[i]++;
				adj[i].push_back(p[i]);
				adj[p[i]].push_back(i);
			}
			vi nx = x;
			sort(all(nx));
			if (nd != nx) {
				continue;
			}
			if (!check(tree, adj)) {
				continue;
			}

			vector<vi> z = {{}};
			rep(i, 0, n) {
				vector<vi> nz;
				for (vi &v : z) {
					vi b(n, true);
					for (int j : v) {
						b[j] = false;
					}
					rep(j, 0, n) {
						if (x[i] != d[j] or !b[j]) {
							continue;
						}
						vi nv = v;
						nv.push_back(j);
						nz.push_back(nv);
					}
				}
				z = nz;
			}
			for (vi &v : z) {
				vector<vi> graph(n);
				rep(j, 1, n) {
					int a = v[j], b = v[p[j]];
					graph[a].push_back(b);
					graph[b].push_back(a);
				}
				rep(j, 0, n) {
					sort(all(graph[j]));
				}
				res += tree == graph;
			}
		}
		rep(i, 2, n) {
			res = mdiv(res, i * i);
		}
		print(mdiv(res, n));
	}
}
