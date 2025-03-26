#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

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
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
};

void dfs(int u, vector<vector<vector<int>>> &v, vector<int> &res, SegTree<int> &s, vector<int> &a) {
	for (vector<int> &i : v[u]) {
		if (i[0] == 1) {
			i[3] = a[i[1]];
			a[i[1]] = i[2];
			s.upd(i[1], i[2]);
		}
		else if (i[0] == 2) {
			res[i[3]] = s.query(i[1], i[2]);
		}
		else {
			dfs(i[1], v, res, s, a);
		}
	}
	reverse(v[u].begin(), v[u].end());
	for (vector<int> i : v[u]) {
		if (i[0] == 1) {
			a[i[1]] = i[3];
			s.upd(i[1], i[3]);
		}
	}
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<int> a(n);
	arrput(a);

	SegTree<int> s(n, 0, [](int a, int b) {
		return a + b;
	});

	rep(i, 0, n) {
		s.upd(i, a[i]);
	}

	vector<vector<vector<int>>> v = {{}};
	rep(i, 0, q) {
		int o;
		input(o);

		if (o == 1) {
			int k, a, x;
			input(k, a, x);
			v[k - 1].push_back({1, a - 1, x, -1});
		}
		else if (o == 2) {
			int k, a, b;
			input(k, a, b);
			v[k - 1].push_back({2, a - 1, b - 1, i});
		}
		else {
			int k;
			input(k);
			v[k - 1].push_back({3, (int) v.size()});
			v.push_back({});
		}
	}

	vector<int> res(q, -1);
	dfs(0, v, res, s, a);

	for (int i : res) {
		if (i != -1) {
			print(i);
		}
	}
}
