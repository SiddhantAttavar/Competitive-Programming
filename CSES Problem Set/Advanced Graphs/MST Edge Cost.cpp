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

#define vi vector<int>

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

const int h = 20;

void dfs(int u, vector<vector<pair<int, int>>> &graph, vector<vector<int>> &p, vector<vector<int>> &a, vector<int> &l) {
	for (auto [v, w] : graph[u]) {
		if (v == p[u][0]) {
			continue;
		}

		l[v] = l[u] + 1;
		p[v][0] = u;
		a[v][0] = w;
		rep(j, 1, h) {
			if (p[v][j - 1] == -1) {
				break;
			}
			p[v][j] = p[p[v][j - 1]][j - 1];
			a[v][j] = max(a[v][j - 1], a[p[v][j - 1]][j - 1]);
		}
		dfs(v, graph, p, a, l);
	}
}

int get(int u, int v, vector<vector<int>> &p, vector<vector<int>> &a, vector<int> &l) {
	if (l[u] < l[v]) {
		swap(u, v);
	}

	int res = 0;
	for (int j = h - 1; j >= 0; j--) {
		if (l[u] >= l[v] + (1 << j)) {
			res = max(res, a[u][j]);
			u = p[u][j];
		}
	}

	if (u == v) {
		return res;
	}

	for (int j = h - 1; j >= 0; j--) {
		if (p[u][j] != p[v][j]) {
			res = max({res, a[u][j], a[v][j]});
			u = p[u][j];
			v = p[v][j];
		}
	}

	return max({res, a[u][0], a[v][0]});
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<array<int, 4>> e(m);
	rep(i, 0, m) {
		int u, v, w;
		input(u, v, w);
		e[i] = {w, u - 1, v - 1, i};
	}
	sort(e.begin(), e.end());

	vector<vector<pair<int, int>>> graph(n);
	UF d(n);
	int c = 0;
	for (auto [w, u, v, i] : e) {
		if (d.join(u, v)) {
			c += w;
			graph[u].push_back({v, w});
			graph[v].push_back({u, w});
		}
	}

	vector<vector<int>> p(n, vector<int>(h, -1)), a(n, vector<int>(h, 0));
	vector<int> l(n, 0);
	dfs(0, graph, p, a, l);

	vector<int> res(m);
	for (auto [w, u, v, i] : e) {
		res[i] = c + w - get(u, v, p, a, l);
	}
	for (int i : res) {
		print(i);
	}
}
