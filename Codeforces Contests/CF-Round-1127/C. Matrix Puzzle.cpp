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

void upd(vector<vi> &v, int i, int j, int x) {
	rep(u, j + 1, sz(v[i])) {
		v[i][u] += x;
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vector<vi> a(n + 1, vi(n + 1, 0));
		rep(i, 0, n) {
			rep(j, 0, n) {
				int x;
				input(x);
				a[i][j] = x;
			}
		}
		rep(i, 0, n) {
			rep(j, 0, n) {
				int x;
				input(x);
				a[i][j] -= x;
			}
		}

		rep(i, 0, n) {
			rep(j, 0, n) {
				a[i][j] = a[i][j] - a[i + 1][j] - a[i][j + 1] + a[i + 1][j + 1];
			}
		}

		vector<vi> v(n, vi(n + 1, 0));
		rep(i, 0, n) {
			rep(j, 0, n) {
				v[i][j + 1] = v[i][j] + (a[i][j] != 0);
			}
		}

		while (q--) {
			char c;
			int i, j, k, l;
			input(c, i, k, j, l);

			i--;
			j--;
			k--;
			l--;

			if (c == 'U') {
				int x;
				input(x);

				if (i > 0 and k > 0) {
					upd(v, i - 1, k - 1, -(a[i - 1][k - 1] != 0));
					a[i - 1][k - 1] += x;
					upd(v, i - 1, k - 1, a[i - 1][k - 1] != 0);
				}
				if (i > 0) {
					upd(v, i - 1, l, -(a[i - 1][l] != 0));
					a[i - 1][l] -= x;
					upd(v, i - 1, l, a[i - 1][l] != 0);
				}
				if (k > 0) {
					upd(v, j, k - 1, -(a[j][k - 1] != 0));
					a[j][k - 1] -= x;
					upd(v, j, k - 1, a[j][k - 1] != 0);
				}
				upd(v, j, l, -(a[j][l] != 0));
				a[j][l] += x;
				upd(v, j, l, a[j][l] != 0);
			}
			else {
				bool flag = true;
				rep(u, i, j) {
					if (v[u][k] != v[u][l]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					print("Yes");
				}
				else {
					print("No");
				}
			}
		}
	}
}
