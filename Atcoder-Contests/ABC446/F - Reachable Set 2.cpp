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

void dfs(int u, int k, int &x, int &y, vector<vi> &graph, vi &vis, vi &w) {
	vis[u] = true;
	x++;
	for (int v : graph[u]) {
		if (vis[v]) {
			continue;
		}
		if (!w[v]) {
			w[v] = true;
			y++;
		}
		if (v <= k and !vis[v]) {
			dfs(v, k, x, y, graph, vis, w);
		}
	}
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vi> graph(n);
	rep(i, 0, m) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
	}

	int x = 0, y = 1;
	vi vis(n, false), w(n, false);
	w[0] = true;
	rep(k, 0, n) {
		if (w[k]) {
			dfs(k, k, x, y, graph, vis, w);
		}
		if (x == k + 1) {
			print(y - x);
		}
		else {
			print(-1);
		}
	}
}
