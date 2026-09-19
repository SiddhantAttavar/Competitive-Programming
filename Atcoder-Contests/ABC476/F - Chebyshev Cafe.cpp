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

int get(int i, int j, int l, int r, vector<vi> &x) {
	if (i > l or j > r) {
		return 0;
	}
	return x[l + 1][r + 1] - x[l + 1][j] - x[i][r + 1] + x[i][j];
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vi a(n), b(n);
	arrput(a);
	arrput(b);

	vector<vi> x(2 * n, vi(2 * n, 0));
	vector<vi> y(2 * n, vi(2 * n, 0));
	vector<vi> z(2 * n, vi(2 * n, 0));
	rep(i, 0, n) {
		rep(j, 0, n) {
			x[i + j + 1][i + n - j] = a[i] * b[j] % m;
			y[i + j + 1][i + n - j] = a[i] * b[j] % m * i;
			z[i + j + 1][i + n - j] = a[i] * b[j] % m * j;
		}
	}
	rep(i, 1, 2 * n) {
		rep(j, 1, 2 * n) {
			x[i][j] += x[i][j - 1] + x[i - 1][j] - x[i - 1][j - 1];
			y[i][j] += y[i][j - 1] + y[i - 1][j] - y[i - 1][j - 1];
			z[i][j] += z[i][j - 1] + z[i - 1][j] - z[i - 1][j - 1];
		}
	}

	int res = 0, k = 2 * n - 2;
	rep(i, 0, n) {
		rep(j, 0, n) {
			int u = i + j, v = i + n - j - 1, c = 0;
			c += get(0, 0, u, v, x) * i - get(0, 0, u, v, y);
			c += get(u + 1, v + 1, k, k, y) - get(u + 1, v + 1, k, k, x) * i;
			c += get(0, v + 1, u, k, x) * j - get(0, v + 1, u, k, z);
			c += get(u + 1, 0, k, v, z) - get(u + 1, 0, k, v, x) * j;
			res ^= c + i * n + j;
		}
	}
	print(res);
}
