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

void dfs(int u, int p, int &c, vector<vector<int>> &graph, string &s, vector<int> &d, vector<vector<bitset<26>>> &a, vector<pair<int, int>> &t, vector<vector<int>> &l) {
	c++;
	t[u].first = c;
	l[d[u]].push_back(c);
	a[d[u]].push_back(a[d[u]].back());
	a[d[u]].back().flip(s[u] - 'a');
	for (int v : graph[u]) {
		if (v != p) {
			d[v] = d[u] + 1;
			dfs(v, u, c, graph, s, d, a, t, l);
		}
	}
	t[u].second = c;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		int p;
		input(p);
		graph[p - 1].push_back(i + 1);
	}

	string s;
	input(s);

	vector<int> d(n, 0);
	vector<pair<int, int>> t(n);
	vector<vector<bitset<26>>> a(n + 1, vector<bitset<26>>(1, 0));
	vector<vector<int>> l(n + 1);
	int c = 0;
	d[0] = 1;
	dfs(0, -1, c, graph, s, d, a, t, l);

	while (m--) {
		int v, h;
		input(v, h);

		v--;

		int i = lower_bound(l[h].begin(), l[h].end(), t[v].first) - l[h].begin();
		int j = upper_bound(l[h].begin(), l[h].end(), t[v].second) - l[h].begin() - 1;
		if (i > j) {
			print("Yes");
			continue;
		}

		if ((a[h][j + 1] ^ a[h][i]).count() <= 1) {
			print("Yes");
		}
		else {
			print("No");
		}
	}
}
