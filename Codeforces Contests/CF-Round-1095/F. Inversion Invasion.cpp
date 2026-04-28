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
const int MOD = 998244353;

int mpow(int a, int b) {
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

int mdiv(int a, int b) {
	return a * mpow(b, MOD - 2) % MOD;
}

const int N = 1e7;
vi fact(N + 1, 1), inv_fact(N + 1, 0);

int perm(int n, int r) {
	if (n < r) {
		return 0;
	}
	return fact[n] * inv_fact[n - r] % MOD;
}

int32_t main() {
	rep(i, 2, N + 1) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	inv_fact[N] = mdiv(1, fact[N]);
	for (int i = N - 1; i >= 0; i--) {
		inv_fact[i] = (i + 1) * inv_fact[i + 1] % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vi x(n + 1, 0), y(n + 1, 0);
		rep(i, 1, n + 1) {
			x[gcd(i, n)]++;
		}

		int c = n - 1, res = fact[n - 1];
		int d = n * (n - 1) / 2, e = n;
		bool flag = false;
		while (q--) {
			int i, p;
			input(i, p);

			if (p < n) {
				res = mdiv(res, fact[c]);
				res = mdiv(res, perm(x[p], y[p]));

				y[p]++;
				c--;
				if (!flag) {
					d -= n - i;
					e--;
				}
				if (y[p] > x[p] or c < 0) {
					res = 0;
				}

				res = res * perm(x[p], y[p]) % MOD;
				res = res * fact[c] % MOD;
			}
			else {
				if (flag) {
					res = 0;
				}
				d = n - i;
				e = 1;
				flag = true;
			}

			int z = (mdiv((n - 1) * (n - 2) % MOD, 4) + mdiv(d % MOD, e)) % MOD;
			print(res * e % MOD * z % MOD);
		}
	}
}
