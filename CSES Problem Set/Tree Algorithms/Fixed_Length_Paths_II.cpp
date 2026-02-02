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
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int dfs(int u, int p, int a, int b, vector<vi> &graph, vector<deque<int>> &s, vi &d) {
	int res = 0;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		d[v] = d[u] + 1;
		res += dfs(v, u, a, b, graph, s, d);
		s[v].push_front(s[v].front());

		if (sz(s[v]) > sz(s[u])) {
			swap(s[v], s[u]);
		}

		rep(i, 0, sz(s[v]) - 1) {
			int l = a - i, r = b - i;
			int x = s[v][i] - s[v][i + 1];
			int y = s[u][max(0ll, min(l, sz(s[u]) - 1))] - s[u][max(0ll, min(r + 1, sz(s[u]) - 1))];
			res += x * y;
		}
		rep(i, 0, sz(s[v])) {
			s[u][i] += s[v][i];
		}
	}
	return res;
}

int32_t main() {
	setup();

	int n, a, b;
	input(n, a, b);

	vector<vi> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<deque<int>> s(n, {1, 0});
	vi d(n, 0);
	print(dfs(0, -1, a, b, graph, s, d));
}
