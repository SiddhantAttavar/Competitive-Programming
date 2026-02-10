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
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

struct RollbackUF {
	vi e; vector<pii> st;
	RollbackUF(int n) : e(n, -1) {}
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : find(e[x]); }
	int time() { return sz(st); }
	void rollback(int t) {
		for (int i = time(); i --> t;)
			e[st[i].first] = st[i].second;
		st.resize(t);
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		st.push_back({a, e[a]});
		st.push_back({b, e[b]});
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void insert(int l, int r, int s, int e, int c, pii p, vector<vector<pii>> &seg) {
	if (l > e or r < s) {
		return;
	}
	if (s <= l and r <= e) {
		seg[c].push_back(p);
		return;
	}
	int m = (l + r) / 2;
	insert(l, m, s, e, 2 * c + 1, p, seg);
	insert(m + 1, r, s, e, 2 * c + 2, p, seg);
}

void dfs(int l, int r, int k, int c, int x, RollbackUF &u, vector<vector<pii>> &seg) {
	if (l > k) {
		return;
	}
	int t = u.time();
	for (auto [i, j] : seg[c]) {
		x -= u.join(i, j);
	}
	if (l == r) {
		cout << x << ' ';
	}
	else {
		int m = (l + r) / 2;
		dfs(l, m, k, 2 * c + 1, x, u, seg);
		dfs(m + 1, r, k, 2 * c + 2, x, u, seg);
	}
	u.rollback(t);
}

int32_t main() {
	setup();

	int n, m, k;
	input(n, m, k);

	map<pii, vi> s;
	rep(i, 0, m) {
		int u, v;
		input(u, v);
		s[{min(u - 1, v - 1), max(u - 1, v - 1)}] = {0};
	}

	rep(i, 0, k) {
		int t, u, v;
		input(t, u, v);
		s[{min(u - 1, v - 1), max(u - 1, v - 1)}].push_back(i + 1);
	}

	vector<vector<pii>> seg(4 * (k + 1));
	for (auto &[p, v] : s) {
		if (sz(v) % 2) {
			v.push_back(k + 1);
		}
		for (int i = 0; i < sz(v); i += 2) {
			insert(0, k, v[i], v[i + 1] - 1, 0, p, seg);
		}
	}

	RollbackUF u(n);
	dfs(0, k, k, 0, n, u, seg);
	cout << endl;
}
