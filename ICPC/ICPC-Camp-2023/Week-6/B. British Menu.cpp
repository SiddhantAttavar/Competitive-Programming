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

#define vi vector<int>
#define sz(x) (int) x.size()

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

void dfs1(int u, vector<vector<pair<int, int>>> &graph, vector<bool> &vis, vector<int> &l) {
	vis[u] = true;
	for (auto [v, w] : graph[u]) {
		if (!vis[v]) {
			dfs1(v, graph, vis, l);
		}
	}
	l.push_back(u);
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<int>> graph(n);
	vector<set<int>> adj(n);
	rep(i, 0, m) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		adj[u - 1].insert(v - 1);
	}

	vector<vector<pair<int, int>>> ngraph(2 * n);
	scc(graph, [&](vector<int> &v) {
		set<int> s(v.begin(), v.end());
		for (int i : v) {
			for (int j : graph[i]) {
				if (!s.count(j)) {
					ngraph[2 * i + 1].push_back({2 * j, 1});
				}
			}
		}

		sort(v.begin(), v.end());
		rep(i, 1, 1 << v.size()) {
			vector<int> a;
			rep(j, 0, v.size()) {
				if (i >> j & 1) {
					a.push_back(v[j]);
				}
			}
			do {
				bool flag = true;
				rep(k, 1, a.size()) {
					if (!adj[a[k - 1]].count(a[k])) {
						flag = false;
						break;
					}
				}
				if (flag) {
					ngraph[2 * a[0]].push_back({2 * a.back() + 1, a.size() - 1});
				}
			} while (next_permutation(a.begin(), a.end()));
		}
	});

	vector<bool> vis(2 * n, false);
	vector<int> l;
	rep(i, 0, 2 * n) {
		if (!vis[i]) {
			dfs1(i, ngraph, vis, l);
		}
	}

	vector<int> dp(2 * n, 1);
	for (int u : l) {
		for (auto [v, w] : ngraph[u]) {
			dp[u] = max(dp[u], dp[v] + w);
		}
	}
	print(*max_element(dp.begin(), dp.end()));
}
