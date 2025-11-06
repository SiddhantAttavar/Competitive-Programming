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
const int MOD = 998244353;

void dfs2(int u, int p, vector<vector<int>> &tree, vector<vector<bool>> &b, vector<int> &x, vector<int> &z) {
	int l = 0, r = x.size() - 1, res = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (b[x[m]][u]) {
			res = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	z.push_back(res + 1);
	for (int v : tree[u]) {
		if (v != p) {
			dfs2(v, u, tree, b, x, z);
		}
	}
}

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}
 
int mod_div(int a, int b) {
	return a * mod_pow(b, MOD - 2) % MOD;
}

int dfs(int u, vector<vector<int>> &tree, vector<int> &a, vector<vector<bool>> &b,  vector<int> l, vector<int> &fact) {
	l.insert(l.begin() + a[u], u);
	rep(i, 0, a[u]) {
		b[l[i]][u] = true;
	}
	int res = 1;
	vector<int> x(l.size() + 1, 0);
	for (int v : tree[u]) {
		res = res * dfs(v, tree, a, b, l, fact) % MOD;
		vector<int> z;
		dfs2(v, u, tree, b, l, z);
		sort(z.begin(), z.end());
		int c = 1;
		rep(i, 1, z.size()) {
			if (z[i] != z[i - 1]) {
				x[z[i - 1]] += c;
				res = mod_div(res, fact[c]);
				c = 0;
			}
			c++;
		}
		x[z.back()] += c;
		res = mod_div(res, fact[c]);
	}
	rep(i, 0, l.size() + 1) {
		res = res * fact[x[i]] % MOD;
	}
	return res;
}

int32_t main() {
	const int N = 1e6;
	vector<int> fact(N + 1, 1);
	rep(i, 2, N + 1) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> tree(n);
		rep(i, 1, n) {
			int p;
			input(p);

			tree[p - 1].push_back(i);
		}

		vector<int> a(n);
		arrput(a);

		vector<int> l;
		vector<vector<bool>> b(n, vector<bool>(n, false));
		print(dfs(0, tree, a, b, l, fact));
	}
}
