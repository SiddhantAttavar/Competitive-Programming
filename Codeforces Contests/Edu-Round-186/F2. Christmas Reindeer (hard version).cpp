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
vi pow2(N + 1, 1), fact(N + 1, 1), inv_fact(N + 1);

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
	setup();

	rep(i, 1, N + 1) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
		fact[i] = fact[i - 1] * i % MOD;
	}
	inv_fact[N] = mdiv(1, fact[N]);
	for (int i = N - 1; i >= 0; i--) {
		inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
	}

	int n, q;
	input(n, q);

	vi c(n);
	arrput(c);

	vi f(61, 0);
	rep(i, 0, n) {
		f[c[i]]++;
	}

	while (q--) {
		int o, x;
		input(o, x);

		if (o == 1) {
			f[x]++;
			continue;
		}
		else if (o == 2) {
			f[x]--;
			continue;
		}

		vi v;
		int s = 0;
		while (x) {
			int i = 63 - __builtin_clzll(x);
			v.push_back(i + s);
			s++;
			x ^= 1ll << i;
		}
		reverse(all(v));

		int res = 0, c = 1, y = accumulate(all(f), 0ll);
		for (int i = 60; i >= 0; i--) {
			y -= f[i];
			int x = 0;
			while (!v.empty() and v.back() == i) {
				x++;
				v.pop_back();
			}
			int z = pow2[f[i]];
			rep(j, 0, x + 1) {
				z = (z - comb(f[i], j) + MOD) % MOD;
			}
			res = (res + c * z % MOD * pow2[y]) % MOD;
			c = c * comb(f[i], x) % MOD;
		}
		res = (res + c) % MOD;
		print(res);
	}
}
