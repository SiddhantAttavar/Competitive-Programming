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

const int N = 2e5;
pair<int, int> v[N];
vector<int> rev_graph[2 * N + 1];
bool vis[2 * N + 1];

void dfs(int u) {
	vis[u] = true;
	for (int v : rev_graph[u]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		rep(i, 0, n) {
			input(v[i].first);
		}
		rep(i, 0, n) {
			input(v[i].second);
		}
		sort(v, v + n);

		map<int, vector<int>> l, m;
		rep(i, 0, n) {
			l[((v[i].first - v[i].second) % k + k) % k].push_back(i);
			m[(v[i].first + v[i].second) % k].push_back(i);
		}

		rep(i, 0, 2 * n + 1) {
			rev_graph[i].clear();
		}
		rep(i, 0, n) {
			int c = ((v[i].first - v[i].second) % k + k) % k;
			int j = upper_bound(l[c].begin(), l[c].end(), i) - l[c].begin();
			if (j < l[c].size()) {
				rev_graph[2 * l[c][j] + 1].push_back(2 * i);
			}
			else {
				rev_graph[2 * n].push_back(2 * i);
			}
		}
		rep(i, 0, n) {
			int c = (v[i].first + v[i].second) % k;
			int j = lower_bound(m[c].begin(), m[c].end(), i) - m[c].begin() - 1;
			if (j >= 0) {
				rev_graph[2 * m[c][j]].push_back(2 * i + 1);
			}
			else {
				rev_graph[2 * n].push_back(2 * i + 1);
			}
		}

		fill(vis, vis + 2 * n + 1, false);
		dfs(2 * n);

		int q;
		input(q);
		while (q--) {
			int x;
			input(x);
			int i = lower_bound(v, v + n, make_pair(x, -1ll)) - v;
			int c = x % k;
			if (i == n or !l.count(c)) {
				print("YES");
				continue;
			}
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
