#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


const ll mod = 1000000007; // faster if const

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

const ll mod = (5 << 25) + 1, root = 62; // = 998244353
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

void solve() {
    int n, k;
    cin >> n >> k;

    vi w(n);
    rep(i, 0, n) {
        cin >> w[i];
    }

    vector<vector<vi>> dpp(n + 1, vector<vi>(n + 1, vi(k + 1, 0)));
    dpp[0][0][0] = 1;
    rep(i, 0, n) {
        dpp[i + 1] = dpp[i];
        rep(l, 1, n + 1) {
            rep(x, w[i], k + 1) {
                dpp[i + 1][l][x] = (dpp[i + 1][l][x] + dpp[i][l - 1][x - w[i]]) % mod;
            }
        }
    }

    vector<vector<vi>> dps(n + 1, vector<vi>(n + 1, vi(k + 1, 0)));
    dps[n][0][0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        dps[i] = dps[i];
        rep(l, 1, n + 1) {
            rep(x, w[i], k + 1) {
                dps[i][l][x] = (dps[i][l][x] + dps[i + 1][l - 1][x - w[i]]) % mod;
            }
        }
    }

    rep(i, 0, n) {
        rep(x, )
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
