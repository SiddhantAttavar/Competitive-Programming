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

#define ll int

const ll mod = (119 << 23) + 1, root = 62; // = 998244353

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
typedef vector<ll> vl;
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s),
	    n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n)
		out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + sz(a)};
}

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

const int N = 1e5;
vi fact(N + 1, 1), inv_fact(N + 1, 1);

vi polypow(vi a, int b) {
	vi res(sz(a), 0);
	res[0] = 1;
	while (b) {
		if (b & 1) {
			res = conv(res, a);
		}
		a = conv(a, a);
		b >>= 1;
	}
	return res;
}

vi geo(vi a, int k) {
	vi res(sz(a), 0);
	res[0] = 1;
	while (k > 1) {
		vi b = a;
		b[0] = (b[0] + 1) % MOD;
		res = conv(res, b);
		a = conv(a, a);
		k >>= 1;
	}
	return res;
}

int32_t main() {
	rep(i, 2, N + 1) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	inv_fact[N] = mdiv(1, fact[N]);
	for (int i = N - 1; i >= 0; i--) {
		inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		int k = 1;
		while (k < n + 1) {
			k *= 2;
		}

		vi p(k);
		rep(i, 0, n + 1) {
			p[i] = inv_fact[i];
		}
		vi q = p;
		q[0] = 0;

		int c = 1;
		rep(i, 0, n + 1) {
			p[i] = c * inv_fact[i] % MOD;
			c = c * (n - m) % MOD;
		}

		vi y = conv(p, polypow(q, m));

		vi g(k, 0);
		g[0] = 1;
		rep(i, 1, n + 1) {
			g[i] = g[i - 1] * n % MOD;
		}
		rep(i, m, n + 1) {
			g[i] = (g[i] - y[i] * fact[i] % MOD + MOD) % MOD;
		}
		g.insert(g.begin(), 0);
		vi z = conv(g, geo(g, k));
		print(z[n + 1]);
	}
}
