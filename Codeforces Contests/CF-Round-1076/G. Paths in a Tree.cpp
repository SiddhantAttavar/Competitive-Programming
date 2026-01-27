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
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

bool debug = false;
int K = -1;
vector<bool> V;

bool dfs1(int u, int p, int x, vector<vi> &graph, vector<bool> &b) {
	b[u] = true;
	if (u == x) {
		return true;
	}
	for (int v : graph[u]) {
		if (v != p and dfs1(v, u, x, graph, b)) {
			return true;
		}
	}
	b[u] = false;
	return false;
}

bool query(int u, int v, vector<vi> &graph) {
	assert(K--);

	if (debug) {
		vector<bool> b(sz(graph));
		dfs1(u, -1, v, graph, b);
		rep(i, 0, sz(graph)) {
			if (b[i] and V[i]) {
				return true;
			}
		}
		return false;
	}

	print('?', u + 1, v + 1);
	cout.flush();
	int x;
	input(x);
	assert(x != -1);
	return x;
}

void dfs2(int u, vector<vi> &graph, vi &m, vi &par) {
	vi l;
	for (int v : graph[u]) {
		if (v == par[u]) {
			continue;
		}
		par[v] = u;
		dfs2(v, graph, m, par);
		if (m[v] == -1) {
			l.push_back(v);
		}
	}
	if (par[u] == -1 and sz(l) % 2 == 0 and !l.empty()) {
		int v = l.back();
		l.pop_back();
		l.push_back(u);
		u = v;
	}
	while (sz(l) >= 2) {
		int a = l[sz(l) - 1], b = l[sz(l) - 2];
		m[a] = b;
		m[b] = a;
		l.pop_back();
		l.pop_back();
	}
	if (!l.empty()) {
		m[l[0]] = u;
		m[u] = l[0];
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int s = -1, t = -1;
		K = n / 2 + 1;
		if (debug) {
			input(s, t);
			s--;
			t--;
		}

		vector<vi> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		if (debug) {
			V.assign(n, false);
			dfs1(s, -1, t, graph, V);
		}

		vi m(n, -1), par(n, -1);
		dfs2(0, graph, m, par);
		assert(count(all(m), -1) == n % 2);

		vector<pii> p, q;
		rep(i, 0, n) {
			if (i >= m[i] or m[i] == -1) {
				continue;
			}
			if (par[i] == m[i] or par[m[i]] == i) {
				p.push_back({i, m[i]});
			}
			else {
				q.push_back({i, m[i]});
			}
		}
		assert(!p.empty());
		q.insert(q.end(), all(p));

		bool flag = false;
		for (auto [u, v] : q) {
			if (!query(u, v, graph)) {
				continue;
			}

			if (query(u, u, graph)) {
				print('!', u + 1);
			}
			else if (par[u] == v or par[v] == u or query(v, v, graph)) {
				print('!', v + 1);
			}
			else {
				print('!', par[u] + 1);
			}
			cout.flush();
			flag = true;
			break;
		}
		if (!flag) {
			int u = find(all(m), -1) - m.begin();
			print('!', u + 1);
			cout.flush();
		}
	}
}

