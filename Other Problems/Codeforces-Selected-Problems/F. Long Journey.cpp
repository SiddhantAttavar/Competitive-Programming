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
	int k = 2520;
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> a(n), b(n);
		arrput(a);
		arrput(b);

		vector<vector<bool>> v(n, vector<bool>(k, true));
		rep(i, 0, n) {
			for (int j = b[i]; j < k; j += a[i]) {
				v[i][j] = false;
			}
		}

		vector<vector<int>> p(n, vector<int>(k, -1));
		rep(i, 0, n) {
			rep(j, 0, k) {
				int u = i;
				rep(l, 0, n) {
					if (v[u][(j + 1) % k]) {
						p[i][j] = l + 1;
						break;
					}
					if (!v[u][j]) {
						break;
					}
					u = (u + 1) % n;
				}
			}
		}

		vector<int> d(n, -1);
		rep(i, 0, n) {
			int z = 0, u = i;
			rep(j, 0, k) {
				if (p[u][j] == -1) {
					z = -1;
					break;
				}
				z += p[u][j];
				u = (u + p[u][j]) % n;
			}
			d[i] = z;
		}

		int res = 0, u = 0, t = 0;
		bool flag = true;
		vector<int> vis(n, -1), z(n, -1);
		while (m >= k and vis[u] == -1) {
			vis[u] = res;
			z[u] = t;
			if (d[u] == -1) {
				flag = false;
				break;
			}
			res += d[u];
			u = (u + d[u]) % n;
			m -= k;
			t++;
		}

		if (!flag) {
			print(-1);
			continue;
		}

		if (vis[u] != -1) {
			int q = k * (t - z[u]);
			res += (res - vis[u]) * (m / q);
			m %= q;
		}

		while (m >= k) {
			if (d[u] == -1) {
				flag = false;
				break;
			}
			res += d[u];
			u = (u + d[u]) % n;
			m -= k;
		}

		rep(i, 0, m) {
			if (p[u][i] == -1) {
				flag = false;
				break;
			}
			res += p[u][i];
			u = (u + p[u][i]) % n;
		}

		if (flag) {
			print(res);
		}
		else {
			print(-1);
		}
	}
}
