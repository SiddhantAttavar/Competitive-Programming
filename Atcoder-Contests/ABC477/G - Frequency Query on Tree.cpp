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
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

template<typename T> struct SegTree { // cmb(ID,b) = b
	T ID; T (*cmb)(T a, T b);
	int n; vector<T> seg;
	SegTree(int _n, T id, T _cmb(T, T)) {
		ID = id; cmb = _cmb;
		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,ID); 
	}
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] += val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
};

void dfs(int u, int p, vector<vi> &graph, vi &a, vi &b, vi &l, vi &d, vector<vi> &q) {
	a[u] = sz(l);
	l.push_back(u);
	for (int v : graph[u]) {
		if (v != p) {
			d[v] = d[u] + 1;
			q[v][0] = u;
			rep(j, 1, 20) {
				if (q[v][j - 1] != -1) {
					q[v][j] = q[q[v][j - 1]][j - 1];
				}
			}
			dfs(v, u, graph, a, b, l, d, q);
		}
	}
	b[u] = sz(l);
	l.push_back(u);
}

int lca(int u, int v, vector<vi> &p, vi &d) {
	if (d[u] < d[v]) {
		swap(u, v);
	}

	for (int i = 19; i >= 0; i--) {
		if (d[u] - (1 << i) >= d[v]) {
			u = p[u][i];
		}
	}

	if (u == v) {
		return u;
	}

	for (int i = 19; i >= 0; i--) {
		if (p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	}

	return p[u][0];
}

void flip(int u, vi &x, vi &f, vi &c, vi &z) {
	assert(u < sz(x));
	if (c[u]) {
		z[f[x[u]]]--;
		f[x[u]]--;
	}
	else {
		f[x[u]]++;
		z[f[x[u]]]++;
	}
	c[u] = !c[u];
}

uint64_t hilbertorder(uint64_t x, uint64_t y) {
    const uint64_t logn = __lg(max(x, y) * 2 + 1) | 1;
    const uint64_t maxn = (1ull << logn) - 1;
    uint64_t res = 0;
    for (uint64_t s = 1ull << (logn - 1); s; s >>= 1) {
        bool rx = x & s, ry = y & s;
        res = (res << 2) | (rx ? ry ? 2 : 1 : ry ? 3 : 0);
        if (!rx) {
            if (ry) x ^= maxn, y ^= maxn;
            swap(x, y);
        }
    }
    return res;
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vi x(n);
	arrput(x);
	rep(i, 0, n) {
		x[i]--;
	}

	vector<vi> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vi a(n), b(n), t, d(n, 0);
	vector<vi> p(n, vi(20, -1));
	dfs(0, -1, graph, a, b, t, d, p);

	vector<array<int, 6>> v(q);
	rep(i, 0, q) {
		int s, t, f, g;
		input(s, t, f, g);

		s--;
		t--;

		if (a[s] > a[t]) {
			swap(s, t);
		}

		int u = lca(s, t, p, d);
		if (u == s) {
			v[i] = {a[s], a[t], -1, f, g, i};
		}
		else {
			v[i] = {b[s], a[t], a[u], f, g, i};
		}
	}

	sort(all(v), [](array<int, 6> a, array<int, 6> b) {
		return hilbertorder(a[0], a[1]) < hilbertorder(b[0], b[1]);
	});

	vi c(n, 0), h(n, 0), z(n + 2, 0), res(q);
	z[0] = n;
	int s = 0, e = -1;
	for (auto [l, r, u, f, g, i] : v) {
		while (s > l) {
			s--;
			flip(t[s], x, h, c, z);
		}
		while (e < r) {
			e++;
			flip(t[e], x, h, c, z);
		}
		while (s < l) {
			flip(t[s], x, h, c, z);
			s++;
		}
		while (e > r) {
			flip(t[e], x, h, c, z);
			e--;
		}

		if (u != -1) {
			flip(t[u], x, h, c, z);
		}
		res[i] = z[f] - z[g + 1];
		if (u != -1) {
			flip(t[u], x, h, c, z);
		}
	}

	for (int i : res) {
		print(i);
	}
}
