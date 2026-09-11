#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
	if (((a - b) % g) != 0) return -1;
	assert((a - b) % g == 0); // else no solution
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

vi Z(const vi& S) {
	vi z(sz(S));
	int l = -1, r = -1;
	rep(i,1,sz(S)) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

pii calc(vi &a, vi &b) {
	a.push_back(-1);
	a.insert(a.end(), all(b));
	a.insert(a.end(), all(b));
	vi z = Z(a), v;
	rep(i, 0, sz(b)) {
		if (z[sz(b) + 1 + i] == sz(b)) {
			v.push_back(i);
		}
	}
	if (v.empty()) {
		return {-1, -1};
	}
	if (sz(v) == 1) {
		return {v[0], sz(b)};
	}
	return {v[0], v[1] - v[0]};
}

void solve() {
    int n;
	cin >> n;

	vi spf(n + 1);
	iota(all(spf), 0);
	rep(i, 2, n + 1) {
		if (spf[i] != i) {
			continue;
		}
		for (int j = i; j <= n; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	vi a(n), b(n), p(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	rep(i, 0, n) {
		cin >> b[i];
	}
	rep(i, 0, n) {
		cin >> p[i];
		p[i]--;
	}

	vi vis(n, false);
	vi v(n + 1, -1);
	rep(i, 0, n) {
		if (vis[i]) {
			continue;
		}

		vi c, d;
		int u = i;
		do {
			vis[u] = true;
			c.push_back(a[u]);
			d.push_back(b[u]);
			u = p[u];
		} while (u != i);

		auto [p, q] = calc(c, d);
		if (p == -1) {
			cout << "IMPOSSIVEL" << endl;
			return;
		}

		if (v[q] != -1 and v[q] != p) {
			cout << "IMPOSSIVEL" << endl;
			return;
		}
		v[q] = p;
		while (q > 1) {
			if (v[spf[q]] != -1 and v[spf[q]] != p % spf[q]) {
				cout << "IMPOSSIVEL" << endl;
				return;
			}
			v[spf[q]] = p % spf[q];
			q /= spf[q];
		}
	}

	int res = 0, z = 1;
	rep(l, 1, n + 1) {
		if (v[l] == -1) {
			continue;
		}

		int x = v[l];
		res = crt(res, z, x, l);
		z = lcm(z, l);
		if (res > (int) 1e9) {
			cout << "DEMAIS" << endl;
			return;
		}
		if (z > (int) 1e9) {
			break;
		}
	}
	rep(l, 1, n + 1) {
		if (v[l] != -1 and res % l != v[l]) {
			cout << "DEMAIS" << endl;
			return;
		}
	}
	cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
