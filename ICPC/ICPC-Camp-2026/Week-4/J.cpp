#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
// typedef long double ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming (``convex hull trick'').
 * Time: O(\log N)
 * Status: stress-tested
 */
// #pragma once

struct Frac {
	__int128_t p, q;
	// __int128_t gcd(__int128_t a, __int128_t b) { if (a == 0) return b; return gcd(b % a, a); }
	__int128_t gcd(__int128_t a, __int128_t b) { return 1; }
	__int128_t abs(__int128_t x) { return x < 0 ? -x : x; }
	Frac(__int128_t x, __int128_t y = 1) { __int128_t g = gcd(abs(x), abs(y)); p = x / g; q = y / g; if (q < 0) {p = -p; q = -q;} }
	Frac norm(Frac f) { __int128_t g = gcd(f.p, f.q); return {f.p / g, f.q / g}; };
	bool operator<(const Frac& f) const { return f.q * p < q * f.p; }
	bool operator>=(const Frac& f) const { return f.q * p >= q * f.p; }
	bool operator==(const Frac& f) const { return f.p * q == p * f.q; }
	Frac operator+(int k) { return norm({p + k * q, q}); }
	Frac operator*(int k) { return norm({p * k, q}); }
};

#define ll Frac

struct Line {
	mutable int k, m;
	mutable ll p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	ll inf = {(int) 4e9, 1}, ninf = {(int) -4e9, 1};
	ll div(int a, int b) { // floored division
		return {a, b};}// - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : ninf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(int k, int m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return x * l.k + l.m;
	}
};

void solve() {
    int m;
	cin >> m;

	LineContainer l;
	vector<array<int, 3>> v;
	rep(i, 0, m) {
		int t, p;
		cin >> t >> p;

		int k = t - p, c = p;
		l.add(k, c);
		v.push_back({k, c, i});
	}
	sort(all(v));

	vector<ll> s, r;
	vi t;
	for (auto [k, m, p] : l) {
		s.push_back(p);
		t.push_back(0);
		r.push_back(p * k + m);
	}

	ll x = {0, 1};
	int p = -1;
	vi z(m);
	auto j = l.begin();
	for (auto [k, c, i] : v) {
		if (j->k == k and j->m == c) {
			j = next(j);
			p++;
		}
		z[i] = p;
	}

	int n;
	cin >> n;
	map<pii, int> f;
	rep(i, 0, n) {
		int a, b;
		cin >> a >> b;
		
		ll x = {a, b};
		int j = lower_bound(all(s), x) - s.begin();
		if (j < sz(s) and s[j] == x) {
			t[j]++;
		}
		else {
			auto j = l.lower_bound(x);
			f[{j->k, j->m}]++;
		}
	}

	vi res(m);
	for (auto [k, c, i] : v) {
		res[i] = f[{k, c}];
		rep(j, max(0ll, z[i] - 2), min(sz(s), z[i] + 3)) {
			if (s[j] * k + c == r[j]) {
				res[i] += t[j];
			}
		}
	}
	for (int i : res) {
		cout << i << endl;
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
