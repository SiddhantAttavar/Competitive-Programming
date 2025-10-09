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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, z;
		input(n, z);

		vector<int> x(n);
		arrput(x);

		vector<vector<int>> a(n, vector<int>(20, n));
		for (int i = n - 1; i >= 0; i--) {
			a[i][0] = upper_bound(x.begin(), x.end(), x[i] + z) - x.begin();
			rep(j, 1, 20) {
				if (a[i][j - 1] < n) {
					a[i][j] = a[a[i][j - 1]][j - 1];
				}
			}
		}

		vector<vector<int>> b(n, vector<int>(20, n)), c(n, vector<int>(20, 0));
		for (int i = n - 2; i >= 0; i--) {
			int u = i, v = i + 1;
			int x = 0;
			for (int j = 19; j >= 0; j--) {
				if (a[u][j] < n and a[v][j] < n and a[u][j] != a[v][j]) {
					x += 1 << (j + 1);
					u = a[u][j];
					v = a[v][j];
				}
			}
			if (a[v][0] < b[i][0]) {
				b[i][0] = a[v][0];
				c[i][0] = x + 2;
			}
			u = i + 1, v = a[i][0];
			int y = 1;
			for (int j = 19; j >= 0; j--) {
				if (v < n and a[u][j] < n and a[v][j] < n and a[u][j] != a[v][j]) {
					y += 1 << (j + 1);
					u = a[u][j];
					v = a[v][j];
				}
			}
			if (u == v) {
				if (v < b[i][0]) {
					b[i][0] = v;
					c[i][0] = y;
				}
			}
			else if (v < n and a[v][0] < b[i][0]) {
				b[i][0] = a[v][0];
				c[i][0] = y + 2;
			}
			rep(j, 1, 20) {
				if (b[i][j - 1] < n) {
					b[i][j] = b[b[i][j - 1]][j - 1];
					c[i][j] = c[i][j - 1] + c[b[i][j - 1]][j - 1];
				}
			}
		}

		int q;
		input(q);
		while (q--) {
			int l, r;
			input(l, r);

			l--;
			r--;

			int res = 0;
			for (int j = 19; j >= 0; j--) {
				if (b[l][j] <= r) {
					res += c[l][j];
					l = b[l][j];
				}
			}

			if (l == r) {
				print(res + 1);
				continue;
			}

			int u = l;
			for (int j = 19; j >= 0; j--) {
				if (a[u][j] <= r) {
					res += 1 << j;
					u = a[u][j];
				}
			}
			res += u <= r;

			u = l + 1;
			for (int j = 19; j >= 0; j--) {
				if (a[u][j] <= r) {
					res += 1 << j;
					u = a[u][j];
				}
			}
			res += u <= r;

			print(res);
		}
	}
}
