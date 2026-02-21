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

void dfs(int u, vector<vi> &graph, vi &vis) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis);
		}
	}
}

int32_t main() {
	setup();

	int n, a, b;
	input(n, a, b);

	vector<vi> graph(n * n);
	rep(i, 0, n) {
		rep(j, 0, n) {
			int k = (a * j + b * i) % n;
			int u = i * n + j, v = j * n + k;
			graph[v].push_back(u);
		}
	}

	vi vis(n * n, false);
	rep(i, 0, n) {
		if (!vis[i * n]) {
			dfs(i * n, graph, vis);
		}
		if (!vis[i]) {
			dfs(i, graph, vis);
		}
	}
	print(n * n - accumulate(all(vis), 0ll));
}
