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
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = 998244353;

const int N = 1e6;
int fact[N + 1], inv_fact[N + 1], pow2[N + 1];

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

int comb(int n, int r) {
	if (n < r) {
		return 0;
	}
	return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int32_t main() {
	fact[0] = 1;
	pow2[0] = 1;
	rep(i, 1, N + 1) {
		fact[i] = fact[i - 1] * i % MOD;
		pow2[i] = pow2[i - 1] * 2 % MOD;
	}
	inv_fact[N] = mdiv(1, fact[N]);
	for (int i = N - 1; i >= 0; i--) {
		inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n);
		arrput(a);
		sort(all(a));

		vi v(n, 0);
		for (int i : a) {
			if (i < n) {
				v[i]++;
			}
		}

		vector<vi> p(n + 1);
		p[0] = vi(n + 1, (pow2[v[0]] - 1 + MOD) % MOD);
		rep(i, 1, n) {
			int l = min(v[i] + 1, sz(p[i - 1]));
			p[i].resize(l);
			p[i][l - 1] = 0;
			rep(j, l - 1, v[i] + 1) {
				p[i][l - 1] = (p[i][l - 1] + comb(v[i], j)) % MOD;
			}
			for (int j = l - 2; j >= 0; j--) {
				p[i][j] = (p[i][j + 1] + comb(v[i], j)) % MOD;
			}
			rep(j, 0, l) {
				p[i][j] = p[i][j] * p[i - 1][j] % MOD;
			}
		}

		int res = 0;
		map<int, int> m;
		for (int i : a) {
			m[i]++;
		}
		m.erase(0);
		for (auto [k, x] : m) {
			int j = upper_bound(all(a), k) - a.begin();
			res = (res + k * pow2[n - j] % MOD * (pow2[x] - 1 + MOD) % MOD) % MOD;
		}
		m.erase(1);
		for (auto [k, x] : m) {
			int j = upper_bound(all(a), k) - a.begin();
			res = (res + (pow2[v[0]] - 1 + MOD) * (k - 1) % MOD * pow2[n - j] % MOD * (pow2[x] - 1 + MOD) % MOD) % MOD;
		}

		rep(x, 2, n + 1) {
			rep(k, 1, sz(p[x - 1])) {
				int j = lower_bound(all(a), x + k) - a.begin();
				res = (res + p[x - 1][k] * pow2[n - j]) % MOD;
			}
		}
		print(res);
	}
}
