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
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = 998244353;

#define ll int

// const ll mod = 1000000007; // faster if const
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
	return {out.begin(), out.begin() + s};
}

vi get(vi &v, int n) {
	vi a(n, 0), b(n, 0);
	for (int i : v) {
		a[i] = 1;
		b[n - i - 1] = 1;
	}
	vi c = conv(a, b), res;
	rep(i, n - 1, sz(c)) {
		if (c[i]) {
			res.push_back(i - (n - 1));
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, x, y;
		input(n, x, y);

		string a;
		input(a);

		vi p(n + 1), s(n + 1), t(n + 1);
		p[0] = 0;
		rep(i, 0, n) {
			if (a[i] == '1') {
				p[i + 1] = y - p[i];
			}
			else {
				p[i + 1] = x + p[i];
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] == '1') {
				s[i] = y - s[i + 1];
			}
			else {
				s[i] = x + s[i + 1];
			}
		}
		rep(i, 0, n) {
			t[i + 1] = t[i] ^ (a[i] == '1');
		}

		set<int> l = {p[n]};
		rep(i, 0, n) {
			if (a[i] != '?') {
				continue;
			}
			if (t[n] ^ t[i]) {
				l.insert({s[i + 1] - y + p[i]});
			}
			else {
				l.insert({s[i + 1] + y - p[i]});
			}
		}

		vi v, w;
		bool flag = true;
		rep(i, 0, n) {
			if (a[i] == '?') {
				v.push_back(i);
			}
			else if (a[i] == '1') {
				swap(v, w);
				flag = !flag;
			}
		}
		if (!flag) {
			swap(v, w);
		}

		vi v1 = get(v, n), v2 = get(w, n);
		for (int i : v1) {
			l.insert(p[n] - 2 * i * x);
		}
		for (int i : v2) {
			l.insert(p[n] + 2 * i * x);
		}

		print(accumulate(all(l), 0ll) % MOD);
	}
}
