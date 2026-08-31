#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void upd(int l, int r, int c, int s, int e, int u, int v, vector<vector<pii>> &b) {
	if (l > e or r < s) {
		return;
	}
	if (s <= l and r <= e) {
		// cout << l << ' ' << r << ' ' << u + 1 << ' ' << v + 1 << endl;
		b[c].push_back({u, v});
		return;
	}
	int m = (l + r) / 2;
	upd(l, m, 2 * c + 1, s, e, u, v, b);
	upd(m + 1, r, 2 * c + 2, s, e, u, v, b);
}

int find(int x, vi &a) {
	if (a[x] < 0) {
		return x;
	}
	return find(a[x], a);
}

void dfs(int l, int r, int c, bool f, vi &res, vi &a, vi &z, vector<pair<vi, vi>> &s, vector<vector<pii>> &b) {
	// cout << l << ' ' << r << ' ' << c << 'n' << endl;

	vector<pii> t;
	for (auto [u, v] : b[c]) {
		// cout << l << ' ' << r << ' ' << u + 1 << ' ' << v + 1 << endl;
		// for (int i : a) {
		// 	cout << i << ' ';
		// }
		// cout << endl;
		int x = find(u, a), y = find(v, a);

		if (x == y) {
			if (z[u] == z[v]) {
				f = false;
			}
			continue;
		}

		if (a[x] > a[y]) {
			swap(x, y);
			swap(u, v);
		}
		// cout << x << ' ' << y << 'r' << endl;

		t.push_back({x, y});
		if (z[u] == z[v]) {
			for (int u : s[y].first) {
				s[x].second.push_back(u);
				z[u] = true;
			}
			for (int u : s[y].second) {
				s[x].first.push_back(u);
				z[u] = false;
			}
		}
		else {
			for (int u : s[y].first) {
				s[x].first.push_back(u);
			}
			for (int u : s[y].second) {
				s[x].second.push_back(u);
			}
		}
		a[x] += a[y];
		a[y] = x;
	}

	if (l == r) {
		res[l] = f;
		// cout << l << ' ' << f << endl;
		// cout.flush();
	}
	else {
		int m = (l + r) / 2;
		dfs(l, m, 2 * c + 1, f, res, a, z, s, b);
		dfs(m + 1, r, 2 * c + 2, f, res, a, z, s, b);
	}

	reverse(all(t));
	for (auto [x, y] : t) {
		// cout << x << ' ' << y << 'd' << endl;
		for (int u : s[y].first) {
			if (z[u]) {
				s[x].second.pop_back();
			}
			else {
				s[x].first.pop_back();
			}
			z[u] = false;
		}
		for (int u : s[y].second) {
			if (z[u]) {
				s[x].second.pop_back();
			}
			else {
				s[x].first.pop_back();
			}
			z[u] = true;
		}

		a[x] = -(sz(s[x].first) + sz(s[x].second));
		a[y] = -(sz(s[y].first) + sz(s[y].second));
		// for (int i : a) {
		// 	cout << i << ' ';
		// }
		// cout << endl;
	}
}

void solve() {
    int n, q;
	cin >> n >> q;

	map<pii, int> m;
	vector<array<int, 4>> a;
	rep(i, 0, q) {
		int x, y;
		cin >> x >> y;

		x--;
		y--;

		if (!m.count({x, y})) {
			m[{x, y}] = i;
		}
		else {
			a.push_back({x, y, m[{x, y}], i - 1});
			m.erase({x, y});
		}
	}

	for (auto [k, v] : m) {
		a.push_back({k.first, k.second, v, q - 1});
	}

	vector<vector<pii>> b(4 * q);
	for (auto [x, y, l, r] : a) {
		// cout << x + 1 << ' ' << y + 1 << ' ' << l << ' ' << r << endl;
		upd(0, q - 1, 0, l, r, x, y, b);
	}

	vi res(q), z(n, -1), y(n, 0);
	vector<pair<vi, vi>> s(n);
	rep(i, 0, n) {
		s[i].first.push_back(i);
	}
	dfs(0, q - 1, 0, true, res, z, y, s, b);

	for (int i : res) {
		if (i) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
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
