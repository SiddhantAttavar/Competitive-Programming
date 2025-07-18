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

struct Med {
	ordered_set o;
	Med() {
		o = ordered_set();
	}
	void insert(int x) {
		o.insert(x);
	}
	int med() {
		int l = 0, r = 1e9, res = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (2 * o.order_of_key(m) < o.size()) {
				res = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		return res;
	}
};

int dfs(int u, vector<vector<int>> &graph, vector<int> &s, vector<Med*> &x, vector<int>  &a) {
	int k = -1, res = 0;
	for (int v : graph[u]) {
		res = max(res, dfs(v, graph, s, x, a));
		s[u] += s[v];
		if (k == -1 or s[v] > s[k]) {
			v = k;
		}
	}
	if (k == -1) {
		x[u] = new Med();
	}
	else {
		x[u] = x[k];
	}
	x[u]->insert(a[u]);
	for (int v : graph[u]) {
		if (k == v) {
			continue;
		}
		for (int i : x[v]->o) {
			x[u]->insert(i);
		}
	}
	print(u, x[u]->med() - a[u], x[u]->med(), x[u]->o.size());
	return max(res, x[u]->med() - a[u]);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		vector<int> l(n, -1), r(n, -1);
		stack<int> s;
		rep(i, 0, n) {
			while (!s.empty() and a[s.top()] > a[i]) {
				s.pop();
			}
			if (!s.empty()) {
				l[i] = s.top();
			}
			s.push(i);
		}
		while (!s.empty()) {
			s.pop();
		}
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() and a[s.top()] >= a[i]) {
				s.pop();
			}
			if (!s.empty()) {
				r[i] = s.top();
			}
			s.push(i);
		}

		vector<vector<int>> graph(n);
		int u = -1;
		rep(i, 0, n) {
			if (l[i] == -1 and r[i] == -1) {
				u = i;
				continue;
			}
			if (l[i] != -1 and (r[i] == -1 or a[l[i]] >= a[r[i]])) {
				graph[l[i]].push_back(i);
			}
			else {
				graph[r[i]].push_back(i);
			}
		}

		vector<int> x(n, 1);
		vector<Med*> v(n);
		print(dfs(u, graph, x, v, a));
	}
}
