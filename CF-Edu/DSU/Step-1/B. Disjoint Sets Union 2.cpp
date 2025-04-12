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

struct DSU {
	vector<int> a, b, c;

	DSU(int n) {
		a.resize(n, -1);
		b.resize(n);
		c.resize(n);
		rep(i, 0, n) {
			b[i] = i + 1;
			c[i] = i + 1;
		}
	}

	int find(int x) {
		if (a[x] < 0) {
			return x;
		}
		return a[x] = find(a[x]);
	}

	bool unite(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) {
			return false;
		}

		if (a[x] > a[y]) {
			swap(x, y);
		}

		a[x] += a[y];
		b[x] = min(b[x], b[y]);
		c[x] = max(c[x], c[y]);
		a[y] = x;
		return true;
	}
};

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	DSU d(n);
	while (q--) {
		string o;
		input(o);

		if (o == "union") {
			int u, v;
			input(u, v);
			d.unite(u - 1, v - 1);
		}
		else {
			int v;
			input(v);
			v = d.find(v - 1);
			print(d.b[v], d.c[v], -d.a[v]);
		}
	}
}
