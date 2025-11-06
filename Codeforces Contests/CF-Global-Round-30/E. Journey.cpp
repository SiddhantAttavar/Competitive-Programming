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

int dfs(int u, int p, int x, vector<vector<int>> &tree, vector<int> &l, vector<bool> &b) {
	x = min(x, l[u]);
	int res = l[u];
	if (b[u]) {
		res += x;
	}
	for (int v : tree[u]) {
		if (v != p) {
			res += dfs(v, u, x, tree, l, b);
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<bool> b(n, false);
		vector<array<int, 4>> e;
		rep(i, 0, m) {
			int u, v, w;
			input(u, v, w);

			u--;
			v--;
			e.push_back({i, u, v, w});
			b[u] = !b[u];
			b[v] = !b[v];
		}

		UF d(n);
		vector<int> l(n, 0);
		vector<vector<int>> tree(n);
		vector<bool> p(n, false);
		vector<int> a(n);
		rep(i, 0, n) {
			a[i] = i;
		}
		for (auto [i, u, v, w] : e) {
			int x = d.find(u);
			int y = d.find(v);
			p.push_back(false);
			l.push_back(w);
			tree.push_back({a[x]});
			if (x != y) {
				tree.back().push_back(a[y]);
				d.join(u, v);
				int z = d.find(u);
				if (b[x] and b[y]) {
					p.back() = true;
					b[z] = false;
				}
				else {
					b[z] = b[x] or b[y];
				}
			}
			int z = d.find(u);
			a[z] = tree.size() - 1;
		}

		print(dfs(tree.size() - 1, -1, 1e18, tree, l, p));
	}
}
