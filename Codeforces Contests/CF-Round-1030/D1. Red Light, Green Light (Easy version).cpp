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

void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis);
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);


		vector<pair<int, int>> v(n);
		rep(i, 0, n) {
			input(v[i].first);
		}
		rep(i, 0, n) {
			input(v[i].second);
		}
		sort(v.begin(), v.end());

		vector<int> p(n), d(n);
		rep(i, 0, n) {
			tie(p[i], d[i]) = v[i];
		}

		vector<vector<int>> l(k), m(k);
		rep(i, 0, n) {
			l[((p[i] - d[i]) % k + k) % k].push_back(i);
			m[(p[i] + d[i]) % k].push_back(i);
		}

		vector<int> graph(2 * n + 1, 2 * n);
		rep(i, 0, n) {
			int c = ((p[i] - d[i]) % k + k) % k;
			int j = upper_bound(l[c].begin(), l[c].end(), i) - l[c].begin();
			if (j < l[c].size()) {
				graph[2 * i] = 2 * l[c][j] + 1;
			}
		}
		rep(i, 0, n) {
			int c = (p[i] + d[i]) % k;
			int j = lower_bound(m[c].begin(), m[c].end(), i) - m[c].begin() - 1;
			if (j >= 0) {
				graph[2 * i + 1] = 2 * m[c][j];
			}
		}

		vector<vector<int>> rev_graph(2 * n + 1);
		rep(i, 0, 2 * n) {
			rev_graph[graph[i]].push_back(i);
		}

		vector<bool> vis(2 * n + 1, false);
		dfs(2 * n, rev_graph, vis);

		int q;
		input(q);

		vector<int> a(q);
		arrput(a);

		for (int x : a) {
			int i = lower_bound(p.begin(), p.end(), x) - p.begin();
			int c = x % k;
			int j = lower_bound(l[c].begin(), l[c].end(), i) - l[c].begin();
			if (j == l[c].size() or vis[2 * l[c][j] + 1]) {
				print("YES");
			}
			else {
				print("NO");
			}
		}
	}
}
