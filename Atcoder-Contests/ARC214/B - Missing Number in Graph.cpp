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

void dfs(int u, vector<vector<pii>> &graph, vi &d) {
	for (auto [v, w] : graph[u]) {
		if (d[v] == -1) {
			d[v] = d[u] ^ w;
			dfs(v, graph, d);
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<pii>> graph(n);
		rep(i, 0, m) {
			int u, v, w;
			input(u, v, w);
			graph[u - 1].push_back({v - 1, w});
			graph[v - 1].push_back({u - 1, w});
		}

		if (n % 2 == 1) {
			print(-1);
			continue;
		}

		vi d(n, -1);
		d[0] = 0;
		dfs(0, graph, d);

		int x = 0;
		rep(i, 1, n + 1) {
			x ^= i;
		}
		rep(i, 0, n) {
			x ^= d[i];
		}
		print(x);
	}
}
