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

void dfs(int u, vector<vi> &graph, vi &vis, vi &t) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis, t);
		}
	}
	t.push_back(u);
}

void mark(int u, vector<vi> &graph, vi &b, vi &vis, vi &dp) {
	vis[u] = true;
	dp[u] = b[u];
	for (int v : graph[u]) {
		if (!vis[v]) {
			mark(v, graph, b, vis, dp);
		}
		dp[u] |= dp[v];
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k, l;
		input(n, m, k, l);

		vi s(k);
		arrput(s);
		rep(i, 0, k) {
			s[i]--;
		}
		s.push_back(0);
		k++;

		vi d(l);
		arrput(d);
		rep(i, 0, l) {
			d[i]--;
		}

		vector<vi> graph(n);
		rep(i, 0, m) {
			int u, v;
			input(u, v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vi x(n, -1);
		queue<int> q;
		x[0] = 0;
		q.push(0);
		vector<vi> adj(n);
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : graph[u]) {
				if (x[v] == -1) {
					x[v] = x[u] + 1;
					q.push(v);
				}
				if (x[v] == x[u] + 1) {
					adj[u].push_back(v);
				}
			}
		}
		vi vis(n, false), t;
		dfs(0, adj, vis, t);
		reverse(all(t));

		vi w(n), b(n);
		rep(i, 0, n) {
			w[t[i]] = i;
		}
		sort(all(s), [&](int i, int j) {
			return w[i] < w[j];
		});
		for (int u : d) {
			b[u] = true;
		}

		vi dp(n, false), z(n, false), p;
		vis.assign(n, false);
		mark(s[k - 1], adj, b, vis, dp);
		while (!t.empty() and t.back() != s[k - 1]) {
			t.pop_back();
		}
		t.pop_back();
		for (int i = k - 1; i > 0; i--) {
			if (!dp[s[i]]) {
				break;
			}
			z[s[i]] = true;
			dp[s[i]] = false;
			p.push_back(s[i]);
			while (!t.empty() and t.back() != s[i - 1]) {
				int u = t.back();
				t.pop_back();
				for (int v : adj[u]) {
					if (z[v] and !z[u]) {
						z[u] = true;
						p.push_back(u);
					}
				}
			}
			int u = s[i - 1];
			for (int v : adj[u]) {
				if (z[v] and !z[u]) {
					z[u] = true;
					p.push_back(u);
				}
			}
			t.pop_back();
			for (int v : p) {
				z[v] = false;
				dp[v] = true;
			}
			p.clear();
		}

		if (!dp[0]) {
			rep(i, 1, n) {
				cout << 0;
			}
			cout << endl;
		}
		else {
			rep(i, 1, n) {
				cout << dp[i];
			}
			cout << endl;
		}
	}
}
