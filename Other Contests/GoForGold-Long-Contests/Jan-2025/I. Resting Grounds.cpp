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

/**
 * Author: Lucian Bicsi
 * Description: 1D point update and range query where \texttt{cmb} is
 	* any associative operation. \texttt{seg[1]==query(0,N-1)}.
 * Time: O(\log N)
 * Source: 
	* http://codeforces.com/blog/entry/18051
	* KACTL
 */

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
	/// int first_at_least(int lo, int val, int ind, int l, int r) { // if seg stores max across range
	/// 	if (r < lo || val > seg[ind]) return -1;
	/// 	if (l == r) return l;
	/// 	int m = (l+r)/2;
	/// 	int res = first_at_least(lo,val,2*ind,l,m); if (res != -1) return res;
	/// 	return first_at_least(lo,val,2*ind+1,m+1,r);
	/// }
};

int32_t main() {
	setup();

	int n, q, r;
	input(n, q, r);

	int m = 1;
	while (m < n) {
		m *= 2;
	}

	vector<vector<pair<int, int>>> graph(4 * m);
	for (int i = m - 1; i > 0; i--) {
		graph[i].push_back({2 * i, 0});
		graph[i].push_back({2 * i + 1, 0});
		graph[2 * i + 2 * m].push_back({i + 2 * m, 0});
		graph[2 * i + 1 + 2 * m].push_back({i + 2 * m, 0});
	}
	rep(i, 0, n) {
		graph[i + m].push_back({i + 3 * m, 0});
		graph[i + 3 * m].push_back({i + m, 0});
	}

	while (q--) {
		int o;
		input(o);

		if (o == 1) {
			int x, y, w;
			input(x, y, w);
			graph[m + x - 1].push_back({m + y - 1, w});
		}
		else if (o == 2) {
			int x, l, r, w;
			input(x, l, r, w);
			for (l += m - 1, r += m, x += m - 1; l < r; l >>= 1, r >>= 1) {
				if (l&1) graph[x].push_back({l++, w});
				if (r&1) graph[x].push_back({--r, w});
			}
		}
		else {
			int x, l, r, w;
			input(x, l, r, w);
			for (l += m - 1, r += m, x += m - 1; l < r; l >>= 1, r >>= 1) {
				if (l&1) graph[l++ + 2 * m].push_back({x + 2 * m, w});
				if (r&1) graph[--r + 2 * m].push_back({x + 2 * m, w});
			}
		}
	}

	vector<int> d(4 * m, 1e18);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[r + m - 1] = 0;
	pq.push({0, r + m - 1});
	while (!pq.empty()) {
		int x, u;
		tie(x, u) = pq.top();
		pq.pop();

		if (x > d[u]) {
			continue;
		}

		for (pair<int, int> p : graph[u]) {
			if (d[u] + p.second < d[p.first]) {
				d[p.first] = d[u] + p.second;
				pq.push({d[p.first], p.first});
			}
		}
	}

	rep(i, 0, n) {
		if (d[i + m] == 1e18) {
			cout << "-1 ";
		}
		else {
			cout << d[i + m] << ' ';
		}
	}
}
