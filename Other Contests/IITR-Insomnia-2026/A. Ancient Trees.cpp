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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

void dfs(int u, int p, vector<vector<pii>> &graph, vi &d, vi &l) {
	for (auto [v, w] : graph[u]) {
		if (v != p) {
			d[v] = d[u] ^ w;
			l[v] = l[u] + 1;
			dfs(v, u, graph, d, l);
		}
	}
}

int32_t main() {
	setup();
	int n, q;
	input(n, q);

	vector<vector<pii>> graph(n);
	rep(i, 0, n - 1) {
		int u, v, w;
		input(u, v, w);
		graph[u - 1].push_back({v - 1, w});
		graph[v - 1].push_back({u - 1, w});
	}
	vi d(n, 0), l(n, 0);
	dfs(0, -1, graph, d, l);

	vi f(30), g(30);
	int x = 0, y = 0;
	rep(i, 0, n) {
		if (l[i] & 1) {
			x++;
		}
		else {
			y++;
		}
		rep(j, 0, 30) {
			if (l[i] & 1) {
				f[j] += d[i] >> j & 1;
			}
			else {
				g[j] += d[i] >> j & 1;
			}
		}
	}

	int z = 0;
	while (q--) {
		int o, i;
		input(o, i);

		if (o == 1) {
			z ^= i;
			continue;
		}

		i--;
		if (!(l[i] & 1)) {
			swap(f, g);
			swap(x, y);
		}

		int res = 0;
		rep(j, 0, 30) {
			if (d[i] >> j & 1) {
				res += (x - f[j]) << j;
			}
			else {
				res += f[j] << j;
			}

			if ((z ^ d[i]) >> j & 1) {
				res += (y - g[j]) << j;
			}
			else {
				res += g[j] << j;
			}
		}
		print(res);

		if (!(l[i] & 1)) {
			swap(f, g);
			swap(x, y);
		}
	}
}
