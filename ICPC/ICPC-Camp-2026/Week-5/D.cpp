#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod = 998244353;

/**
 * Author: Unknown
 * Date: 2002-09-15
 * Source: predates tinyKACTL
 * Description: Finds two integers $x$ and $y$, such that $ax+by=\gcd(a,b)$. If
 * you just need gcd, use the built in \texttt{\_\_gcd} instead.
 * If $a$ and $b$ are coprime, then $x$ is the inverse of $a \pmod{b}$.
 */
// #pragma once

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

int floor_sum(int a, int b, int c, int n) {
	// int res = 0;
	// rep(i, 0, n + 1) {
	// 	res += (a * i + b) / c;
	// }
	// return res;
	if (!a) {
		return (b / c) % mod * (n + 1) % mod;
	}
	if (a >= c or b >= c) {
		int res = (n * (n + 1) / 2) % mod * (a / c) % mod + (n + 1) % mod;
		return (res + floor_sum(a % c, b % c, c, n)) % mod;
	}
	int m = (a * n + b) / c;
	return (m % mod * n % mod - floor_sum(c, c - b - 1, a, m - 1) + mod) % mod;
}

int minv(int a, int b) {
	assert(gcd(a, b) == 1);
	int x, y;
	euclid(a, b, x, y);
	return x;
}

int solve(int a, int b, int c, int x, int y, int z, int t) {
	if (t < 0) {
		return 0;
	}

	int g = gcd(a, b);
	a /= g;
	b /= g;

	int q = t * minv(c, g) % g;
	if (t < c * q) {
		return 0;
	}
	
	int s = (t - c * q) / g, res = 0;
	rep(l, 0, a) {
		if (s < c * l) {
			break;
		}
		int j = (s - c * l) * minv(b, a) % a;
		int u = s - c * l - b * j;
		if (u < 0) {
			continue;
		}
		u /= a;
		
		int t = min(b - 1, u / c);
		cout << l << ' ' << j << ' ' << u << ' ' << t << endl;
		cout << floor_sum(c, u - t * c + b * c, b * c, t) << endl;
		res = (res + floor_sum(c, u - t * c + b * c, b * c, t)) % mod;
	}
	return res;
}

void solve() {
    int a, b, c, t, x, y, z;
	cin >> a >> b >> c >> t >> x >> y >> z;

	int g = gcd(gcd(a, b), c);
	if (t % g) {
		cout << 0 << endl;
		return;
	}
	a /= g;
	b /= g;
	c /= g;
	t /= g;
	x /= g;
	y /= g;
	z /= g;

	int res = 0;
	rep(i, 0, 8) {
		int s = t;
		bool flag = false;
		if (i & 1) {
			s -= (x + 1) * a;
			flag = !flag;
		}
		if (i & 2) {
			s -= (y + 1) * b;
			flag = !flag;
		}
		if (i & 4) {
			s -= (z + 1) * b;
			flag = !flag;
		}
		int u = solve(a, b, c, x, y, z, s);
		if (flag) {
			res = (res - u + mod) % mod;
		}
		else {
			res = (res + u) % mod;
		}
	}
	cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
