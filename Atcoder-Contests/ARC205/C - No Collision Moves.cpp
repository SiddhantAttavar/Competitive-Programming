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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void dfs(int u, vector<vector<int>> &graph, vector<int> &l, vector<bool> &vis) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, l, vis);
		}
	}
	l.push_back(u + 1);
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<pair<pair<int, int>, int>> v(n);
	vector<int> s(n), t(n);
	rep(i, 0, n) {
		input(s[i], t[i]);
		v[i] = {{s[i], t[i]}, i};
	}
	sort(v.begin(), v.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return min(a.first.first, a.first.second) < min(b.first.first, b.first.second);
	});

	for (auto [p, i] : v) {
	}

	int x = -1, y = -1;
	int c = 0;
	vector<vector<int>> graph(n);
	for (auto [p, i] : v) {
		if (c > max(p.first, p.second)) {
			print("No");
			return 0;
		}
		c = max(p.first, p.second);
		if (x != -1 and t[x] < min(p.first, p.second)) {
			x = -1;
		}
		if (y != -1 and s[y] < min(p.first, p.second)) {
			y = -1;
		}

		if (p.first < p.second) {
			if (x != -1) {
				graph[i].push_back(x);
			}
			if (y != -1) {
				print("No");
				return 0;
			}
			x = i;
		}
		else {
			if (x != -1) {
				print("No");
				return 0;
			}
			if (y != -1) {
				graph[y].push_back(i);
			}
			y = i;
		}
	}

	print("Yes");
	vector<bool> vis(n, false);
	vector<int> l;
	rep(i, 0, n) {
		if (!vis[i]) {
			dfs(i, graph, l, vis);
		}
	}
	reverse(l.begin(), l.end());
	arrprint(l);
}
