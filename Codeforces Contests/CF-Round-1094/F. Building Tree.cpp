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

void insert(int c, int l, int r, int s, int e, int x, vector<vi> &seg) {
	if (l > e or r < s) {
		return;
	}
	if (s <= l and r <= e) {
		seg[c].push_back(x);
		return;
	}
	int m = (l + r) / 2;
	insert(2 * c + 1, l, m, s, e, x, seg);
	insert(2 * c + 2, m + 1, r, s, e, x, seg);
}

struct RollbackUF {
	vi e; vi d; vector<pair<int*, int>> st;
	RollbackUF(int n) : e(n, -1), d(n, -1) {}
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : find(e[x]); }
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
		st.push_back({&e[a], e[a]});
		st.push_back({&e[b], e[b]});
		st.push_back({&d[a], d[a]});
		e[a] += e[b]; e[b] = a;
		if (d[a] == -1) d[a] = d[b];
		return true;
	}
};

int dfs(int c, int l, int r, vector<pii> &p, vector<vector<pii>> &edges, vector<vi> &seg, RollbackUF &d, RollbackUF &e) {
	int t = d.time(), res = 0;
	for (int i : seg[c]) {
		for (auto [u, v] : edges[i]) {
			u = d.find(u);
			v = d.find(v);
			if (d.d[u] != -1 and d.d[v] != -1 and u != v) {
				p.push_back({d.d[u], d.d[v]});
			}
			d.join(u, v);
		}
	}

	if (l < r) {
		int m = (l + r) / 2;
		res += dfs(2 * c + 1, l, m, p, edges, seg, d, e);
		res += dfs(2 * c + 2, m + 1, r, p, edges, seg, d, e);
	}
	else {
		for (auto [u, v] : p) {
			if (e.find(u) != e.find(v)) {
				res += l;
			}
			e.join(u, v);
		}
		p.clear();
	}

	d.rollback(t);
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, q;
		input(n, m, q);

		vector<vector<pii>> edges(m + 1);
		rep(i, 0, m) {
			int u, v, w;
			input(u, v, w);
			edges[w].push_back({u - 1, v - 1});
		}

		vi b(n, false);
		while (q--) {
			int x;
			input(x);
			b[x - 1] = true;
		}

		vector<vi> seg(4 * (m + 1));
		rep(i, 0, m + 1) {
			if (i) {
				insert(0, 0, m, 0, i - 1, i, seg);
			}
			if (i < m) {
				insert(0, 0, m, i + 1, m, i, seg);
			}
		}

		RollbackUF d(n), e(n);
		rep(i, 0, n) {
			if (b[i]) {
				d.d[i] = i;
			}
		}

		vector<pii> p;
		int res = dfs(0, 0, m, p, edges, seg, d, e);

		int x = -1;
		rep(i, 0, n) {
			if (!b[i]) {
				continue;
			}
			if (x == -1) {
				x = e.find(i);
			}
			else if (e.find(i) != x) {
				res = -1;
				break;
			}
		}
		print(res);
	}
}
