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
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi b(n);
		arrput(b);

		vi c(n, -1), d(n + 1, 0), a(n, -1), x(n, true);
		rep(i, 0, n) {
			if (b[i] > 0) {
				int l = max(0ll, i - b[i] + 1), r = min(n - 1, i + b[i] - 1);
				d[l]++;
				d[r + 1]--;
			}
		}
		rep(i, 0, n) {
			d[i + 1] += d[i];
			if (d[i]) {
				c[i] = false;
			}
		}

		bool flag = true;
		rep(i, 0, n) {
			if (b[i] == -1) {
				continue;
			}

			if (b[i] == 0) {
				if (c[i] == false) {
					flag = false;
				}
				c[i] = true;
				continue;
			}

			if (i - b[i] < 0 or c[i - b[i]] == false) {
				if (i + b[i] < n and c[i + b[i]] != 0) {
					c[i + b[i]] = true;
				}
				else {
					flag = false;
				}
			}
			if (i + b[i] >= n or c[i + b[i]] == false) {
				if (i - b[i] >= 0 and c[i - b[i]] != 0) {
					c[i - b[i]] = true;
				}
				else {
					flag = false;
				}
			}

			if (i - b[i] >= 0 and i + b[i] < n and c[i - b[i]] == -1 and c[i + b[i]] == -1) {
				a[i + b[i]] = i - b[i];
				x[i - b[i]] = false;
			}
		}

		if (!flag) {
			print(0);
			continue;
		}

		vi f(n, 1), g(n, 1);
		int res = 1;
		rep(i, 0, n) {
			if (a[i] != -1) {
				f[i] = (f[a[i]] + g[a[i]]) % MOD;
				g[i] = f[a[i]];
			}
			if (c[i] == 1) {
				g[i] = 0;
			}
			else if (c[i] == 0) {
				f[i] = 0;
			}
			if (x[i]) {
				res = res * (f[i] + g[i]) % MOD;
			}
		}
		if (count(all(b), -1) == n) {
			res = (res + MOD - 1) % MOD;
		}
		print(res);
	}
}
