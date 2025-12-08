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

#define sz(x) (int) x.size()
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define ll long long

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

typedef vector<ll> vl;
template<int M> vl convMod(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	vl res(sz(a) + sz(b) - 1);
	int B=32-__builtin_clz(sz(res)), n=1<<B, cut=(int)(sqrt(M));
	vector<C> L(n), R(n), outs(n), outl(n);
	rep(i,0,sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
	rep(i,0,sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
	fft(L), fft(R);
	rep(i,0,n) {
		int j = -i & (n - 1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
	}
	fft(outl), fft(outs);
	rep(i,0,sz(res)) {
		ll av = (ll)(real(outl[i])+.5), cv = (ll)(imag(outs[i])+.5);
		ll bv = (ll)(imag(outl[i])+.5) + (ll)(real(outs[i])+.5);
		res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
	}
	return res;
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

int ncr(int n, int r, vector<int> &fact) {
	if (r < 0 or n < 0 or r > n) {
		return 0;
	}
	return mdiv(fact[n], fact[r] * fact[n - r] % MOD);
}

vector<int> polypow(vector<int> &a, int b) {
	int n = a.size();
	vector<int> res = {1};
	while (b) {
		if (b & 1) {
			res = convMod<MOD>(res, a);
			res.resize(n);
		}
		a = convMod<MOD>(a, a);
		a.resize(n);
		b >>= 1;
	}
	return res;
}

int32_t main() {
	const int N = 1e4;
	vector<int> fact(N + 1, 1);
	rep(i, 2, N + 1) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> f(m, 0);
		rep(i, 0, n) {
			int c;
			input(c);
			f[c - 1]++;
		}

		vector<int> b(m);
		arrput(b);

		if (n == 1) {
			bool flag = true;
			rep(i, 0, m) {
				flag = flag and f[i] == !b[i];
			}
			print(flag);
			continue;
		}

		vector<int> ne(n + 1, 0), no(n + 1, 0);
		rep(i, 0, m) {
			if (b[i] ^ (f[i] & 1)) {
				no[f[i]]++;
			}
			else {
				ne[f[i]]++;
			}
		}

		vector<int> res(n - 1, 0);
		res[0] = fact[n - 2];
		rep(i, 0, n + 1) {
			if (!ne[i]) {
				continue;
			}
			vector<int> a(n - 1, 0);
			for (int j = 0; j < n - 1; j += 2) {
				a[j] = mdiv(mpow(i, j), fact[j]);
			}
			res = convMod<MOD>(res, polypow(a, ne[i]));
			res.resize(n - 1);
		}
		rep(i, 0, n + 1) {
			if (!no[i]) {
				continue;
			}
			vector<int> a(n - 1, 0);
			for (int j = 1; j < n - 1; j += 2) {
				a[j] = mdiv(mpow(i, j), fact[j]);
			}
			res = convMod<MOD>(res, polypow(a, no[i]));
			res.resize(n - 1);
		}
		print(res[n - 2]);
	}
}
