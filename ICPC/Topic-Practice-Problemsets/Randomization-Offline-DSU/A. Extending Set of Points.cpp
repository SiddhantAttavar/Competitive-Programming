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
const int MOD = (int) 1e9 + 7; //998244353;

struct RollbackUF {
	vi e, p, q, x, y; vector<pair<vi::iterator, int>> st;
	RollbackUF(int n) {
		e.resize(2 * n, -1);
		p.resize(2 * n, 0);
		q.resize(2 * n, 0);
		x.resize(2 * n, 0);
		y.resize(2 * n, 0);
		fill(x.begin(), x.begin() + n, 1);
		fill(y.begin() + n, y.end(), 1);
	}
	int size(int a) { return -e[find(a)]; }
	int find(int a) { return e[a] < 0 ? a : find(e[a]); }
	int time() { return sz(st); }
	void rollback(int t) {
		for (int i = time(); i --> t;)
			*st[i].first = st[i].second;
		st.resize(t);
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);

		st.push_back({e.begin() + a, e[a]});
		st.push_back({p.begin() + a, p[a]});
		st.push_back({q.begin() + a, q[a]});
		st.push_back({x.begin() + a, x[a]});
		st.push_back({y.begin() + a, y[a]});
		st.push_back({e.begin() + b, e[b]});
		st.push_back({x.begin() + b, x[b]});
		st.push_back({y.begin() + b, y[b]});

		e[a] += e[b];
		e[b] = a;
		p[a] += p[b] + x[a] + x[b];
		q[a] += q[b] + y[a] + y[b];
		x[a] = x[b] = 0;
		y[a] = y[b] = 0;

		return true;
	}
};

void solve(int l, int r, int a, vector<array<int, 4>> &z, RollbackUF &d, int n, vi &res) {
	int t = d.time();
	if (l == r) {
		for (auto [s, e, x, y] : z) {
			x = d.find(x);
			y = d.find(y);
			if (x != y) {
				a -= d.p[x] * d.q[x] + d.p[y] * d.q[y];
				d.join(x, y);
				x = d.find(x);
				a += d.p[x] * d.q[x];
			}
		}
		res[l] = a;
		d.rollback(t);
		return;
	}

	int m = (l + r) / 2;
	vector<array<int, 4>> f, g;
	for (auto [s, e, x, y] : z) {
		if (s <= l and r <= e) {
			x = d.find(x);
			y = d.find(y);
			if (x != y) {
				a -= d.p[x] * d.q[x] + d.p[y] * d.q[y];
				d.join(x, y);
				x = d.find(x);
				a += d.p[x] * d.q[x];
			}
			continue;
		}

		if (s <= m) {
			f.push_back({s, e, x, y});
		}
		if (e > m) {
			g.push_back({s, e, x, y});
		}
	}

	solve(l, m, a, f, d, n, res);
	solve(m + 1, r, a, g, d, n, res);
	d.rollback(t);
}

int32_t main() {
	setup();

	int q;
	input(q);

	map<int, int> s, t;
	map<pii, int> a;
	vector<array<int, 4>> z;
	rep(i, 0, q) {
		int x, y;
		input(x, y);

		if (!s.count(x)) {
			s[x] = sz(s);
		}
		if (!t.count(y)) {
			t[y] = sz(t);
		}

		pii p = {s[x], t[y] + q};
		if (a.count(p)) {
			z.push_back({a[p], i - 1, p.first, p.second});
			a.erase(p);
		}
		else {
			a[p] = i;
		}
	}
	for (auto [p, i] : a) {
		z.push_back({i, q - 1, p.first, p.second});
	}

	RollbackUF d(q);
	vi res(q + 1);
	solve(0, q, 0, z, d, sz(s), res);
	res.pop_back();
	arrprint(res);
}
