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

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

void dfs1(int u, vector<set<int>> &adj, vi &vis, vi &l) {
	vis[u] = true;
	for (int v : adj[u]) {
		if (!vis[v]) {
			dfs1(v, adj, vis, l);
		}
	}
	l.push_back(u);
}

int32_t main() {
	setup();

	int n, m, q;
	input(n, m, q);

	vector<vi> graph(n);
	rep(i, 0, m) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
	}

	scc(graph, [](vi &v) {});

	vector<set<int>> adj(ncomps);
	rep(u, 0, n) {
		for (int v : graph[u]) {
			adj[comp[u]].insert(comp[v]);
		}
	}

	vi vis(ncomps, false), l;
	rep(i, 0, ncomps) {
		if (!vis[i]) {
			dfs1(i, adj, vis, l);
		}
	}

	const int N = 5e4;
	vector<bitset<N>> v(ncomps);
	for (int i : l) {
		v[i][i] = true;
		for (int j : adj[i]) {
			v[i] |= v[j];
		}
	}
	
	while (q--) {
		int x, y;
		input(x, y);

		x--;
		y--;

		if (v[comp[x]][comp[y]]) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
