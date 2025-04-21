#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e4;
const int MOD = (int) 1e9 + 7;
int seg[4 * N][10][10];
bool graph[N][10][10];

void matmul(int a[10][10], int b[10][10], int c[10][10]) {
	int d[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			d[i][j] = 0;
			for (int k = 0; k < 10; k++) {
				d[i][j] = (d[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			c[i][j] = d[i][j];
		}
	}
}

void build(int s, int e, int i) {
	if (s == e) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				seg[i][j][k] = graph[s][j][k];
			}
		}
		return;
	}

	int m = (s + e) / 2;
	build(s, m, 2 * i);
	build(m + 1, e, 2 * i + 1);
	matmul(seg[2 * i], seg[2 * i + 1], seg[i]);
}

void update(int s, int e, int i, int j, int x, int y) {
	if (s > j or e < j) {
		return;
	}
	if (s == e) {
		seg[i][x][y] = graph[j][x][y];
		return;
	}
	
	int m = (s + e) / 2;
	update(s, m, 2 * i, j, x, y);
	update(m + 1, e, 2 * i + 1, j, x, y);
	matmul(seg[2 * i], seg[2 * i + 1], seg[i]);
}

void query(int s, int e, int i, int l, int r, int a[10][10]) {
	if (s > r or e < l) {
		return;
	}
	if (l <= s and e <= r) {
		matmul(a, seg[i], a);
		return;
	}

	int m = (s + e) / 2;
	query(s, m, 2 * i, l, r, a);
	query(m + 1, e, 2 * i + 1, l, r, a);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				graph[i][j][k] = 1;
			}
		}
	}
	build(0, n - 2, 1);

	while (q--) {
		int o;
		cin >> o;

		if (o == 1) {
			int i, j, k;
			cin >> i >> j >> k;
			i--;
			graph[i][j][k] = 1 - graph[i][j][k];
			update(0, n - 2, 1, i, j, k);
		}
		else {
			int m, c;
			cin >> m >> c;
			int a[10][10];
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					a[i][j] = 0;
				}
			}
			a[c][c] = 1;
			query(0, n - 2, 1, 0, m - 2, a);
			cout << accumulate(a[c], a[c] + 10, 0ll) % MOD << endl;
		}
	}
}

// #include <bits/stdc++.h>
// #include <bits/extc++.h>
// using namespace std;
// using namespace __gnu_pbds; 
// template<typename T> inline void input(T& x) {cin >> x;}
// template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
// template<typename T> inline void print(T x) {cout << x << '\n';}
// template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
// template<typename T> inline void dbg(T x) {cerr << x << '\n';}
// template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
// #define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
// #define rep(i, a, b) for (auto i = (a); i < (b); i++)
// #define arrput(l) for (auto &i : l) {cin >> i;}
// #define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
// #define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define int long long
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
// const int MOD = (int) 1e9 + 7; //998244353;
//
// vector<vector<int>> matmul(vector<vector<int>> &a, vector<vector<int>> &b) {
// 	vector<vector<int>> res(a.size(), vector<int>(b[0].size(), 0));
// 	rep(i, 0, res.size()) {
// 		rep(j, 0, res[0].size()) {
// 			rep(k, 0, a[0].size()) {
// 				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
// 			}
// 		}
// 	}
// 	return res;
// }
//
// template<typename T> struct SegTree {
// 	T ID; T (*cmb)(T a, T b);
// 	int n; vector<T> seg;
// 	SegTree(int _n, T id, T _cmb(T, T)) {
// 		ID = id; cmb = _cmb;
// 		for (n = 1; n < _n; ) n *= 2; 
// 		seg.assign(2*n,ID); 
// 	}
// 	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
// 	void upd(int p, T val) {
// 		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
// 	T query(int l, int r) {
// 		T ra = ID, rb = ID;
// 		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
// 			if (l&1) ra = cmb(ra,seg[l++]);
// 			if (r&1) rb = cmb(seg[--r],rb);
// 		}
// 		return cmb(ra,rb);
// 	}
// };
//
// int32_t main() {
// 	setup();
//
// 	int n, q;
// 	input(n, q);
//
// 	vector<vector<int>> id(10, vector<int>(10, 0));
// 	rep(i, 0, 10) {
// 		id[i][i] = 1;
// 	}
// 	SegTree<vector<vector<int>>> s(n - 1, id, [](vector<vector<int>> a, vector<vector<int>> b) {
// 		return matmul(a, b);
// 	});
//
// 	vector<vector<vector<int>>> graph(n - 1, vector<vector<int>>(10, vector<int>(10, 1)));
// 	rep(i, 0, n - 1) {
// 		s.seg[s.n + i] = graph[i];
// 	}
// 	for (int i = s.n - 1; i > 0; i--) {
// 		s.seg[i] = s.cmb(s.seg[2 * i], s.seg[2 * i + 1]);
// 	}
// 	while (q--) {
// 		int o;
// 		input(o);
//
// 		if (o == 1) {
// 			int i, j, l;
// 			input(i, j, l);
// 			i--;
//
// 			graph[i][j][l] = 1 - graph[i][j][l];
// 			s.upd(i, graph[i]);
// 		}
// 		else {
// 			int m, c;
// 			input(m, c);
// 			m--;
//
// 			vector<vector<int>> a = s.query(0, m - 1);
// 			for (vector<int> v : a) {
// 				arrprint(v);
// 			}
// 			print(accumulate(a[c].begin(), a[c].end(), 0ll) % MOD);
// 		}
// 	}
// }
