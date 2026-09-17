#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: chilli
 * License: CC0
 * Description: z[i] computes the length of the longest common prefix of s[i:] and s,
 * except z[0] = 0. (abacaba -> 0010301)
 * Time: O(n)
 * Status: stress-tested
 */
// #pragma once

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

void solve() {
    int n;
	cin >> n;

	vi z(n);
	rep(i, 0, n) {
		cin >> z[i];
	}

	vector<vi> t(n + 1);
	vector<set<int>> s(n + 1);
	vi v(n);
	multiset<int> m;
	rep(i, 0, n) {
		m.insert(-i);
		t[i + z[i]].push_back(-i);
		s[i + z[i]].insert(z[i]);
		for (int j : t[i]) {
			m.erase(j);
		}
		if (m.empty()) {
			v[i] = i;
		}
		else {
			v[i] = i + *m.begin();
		}
	}

	
	vi p(n + 1);
	iota(all(p), 0);
	rep(i, 0, n) {
		p[i] = p[v[i]];
	}

	set<pii> e;
	rep(i, 0, n) {
		for (int j : s[i]) {
			e.insert({p[i], p[j]});
			e.insert({p[j], p[i]});
		}
	}
	p.erase(p.begin());
	
	vi a = Z(p);
	rep(i, 0, n - 1) {
		if (i + a[i] < n - 1 and !e.count({p[a[i]], p[i + a[i]]})) {
			a[i] = -1;
		}
	}

	cout << n - 1;
	rep(i, 1, n - 1) {
		cout << ' ' << a[i];
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
