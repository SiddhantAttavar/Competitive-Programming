#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void dfs(int u, vector<vector<pair<int, int>>> &graph, vector<int> &a, vector<int> &b, vector<int> &d, int &t) {
	a[u] = t++;
	for (pair<int, int> i : graph[u]) {
		d[i.first] = d[u] + i.second;
		dfs(i.first, graph, a, b, d, t);
	}
	b[u] = t++;
}


#define vi vector<int>
#define sz(x) (int) x.size()

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

int dfs2(int u, vector<vector<pair<int, int>>> &tree) {
	int res = 0;
	for (pair<int, int> p : tree[u]) {
		res = max(res, dfs2(p.first, tree) + p.second);
	}
	return res;
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<vector<pair<int, int>>> graph(n);
	vector<vector<int>> adj(n);
	rep(i, 1, n) {
		int p, w;
		input(p, w);

		graph[p - 1].push_back({i, w});
		adj[p - 1].push_back(i);
	}

	vector<int> a(n), b(n), d(n, 0);
	int t = 0;
	dfs(0, graph, a, b, d, t);

	LCA l(adj);

	while (q--) {
		int k;
		input(k);

		vector<int> v(k);
		arrput(v);
		rep(i, 0, k) {
			v[i]--;
		}
		sort(v.begin(), v.end(), [&](int x, int y) {
			return a[x] < a[y];
		});

		set<int> s(v.begin(), v.end());
		rep(i, 0, k - 1) {
			s.insert(l.lca(v[i], v[i + 1]));
		}
		s.insert(0);

		vector<int> w(s.begin(), s.end());
		sort(w.begin(), w.end(), [&](int x, int y) {
			return a[x] < a[y];
		});

		vector<vector<pair<int, int>>> tree(w.size());
		stack<int> x;
		x.push(0);
		rep(i, 1, w.size()) {
			while (b[w[i]] > b[w[x.top()]]) {
				x.pop();
			}
			tree[x.top()].push_back({i, d[w[i]] - d[w[x.top()]]});
			x.push(i);
		}

		int res = 0;
		for (vector<pair<int, int>> i : tree) {
			for (pair<int, int> j : i) {
				res += j.second;
			}
		}
		print(2 * res - dfs2(0, tree));
	}
}
