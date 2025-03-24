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

template<typename T, int SZ> struct SegTree {
	vector<T> seg; T id;
	T (*cmb) (T, T);
	SegTree(T _id, T _cmb(T, T)):id(_id),seg(2*SZ,id),cmb(_cmb){}
	void build() {for (int i=SZ-1; i >= 0; i--) seg[i]=cmb(seg[2*i],seg[2*i+1]);}
	T query(int l, int r, int s=0, int e=SZ-1, int c=1) {
		if (l > e || r < s) return id;
		if (l <= s && r >= e) return seg[c];
		int mid = (s + e) / 2;
		return cmb(query(l,r, s, mid, 2*c),
			query(l, r, mid + 1, e, 2*c+1));
	}
	void update(int i, T x, int s=0, int e=SZ-1, int c=1) {
		if (s > i || e < i) return;
		if (s == e) {seg[c] = x; return;}
		int mid = (s + e) / 2;
		update(i, x, s, mid, 2*c);
		update(i, x, mid + 1, e, 2*c+1);
		seg[c] = cmb(seg[2*c], seg[2*c+1]);
	}
	void update2(int l, int r, int x, int s=0, int e=SZ-1, int c=1) {
		if (s > r || e < l) return;
		if (l <= s and e <= r) {
			if (seg[c].second < x) return;
			if (s == e) {
				seg[c].first %= x;
				seg[c].second %= x;
			}
		}
		if (s != e) {
			int mid = (s + e) / 2;
			update2(l, r, x, s, mid, 2*c);
			update2(l, r, x, mid + 1, e, 2*c+1);
			seg[c] = cmb(seg[2*c], seg[2*c+1]);
		}
	}
};

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<int> a(n);
	arrput(a);

	SegTree<pair<int, int>, 1 << 18> s({0, 0}, [](pair<int, int> a, pair<int, int> b) {
		return make_pair(a.first + b.first, max(a.second, b.second));
	});
	rep(i, 0, n) {
		s.seg[i + (1 << 18)] = {a[i], a[i]};
	}
	s.build();

	while (q--) {
		int o;
		input(o);

		if (o == 1) {
			int l, r;
			input(l, r);
			print(s.query(l - 1, r - 1).first);
		}
		else if (o == 2) {
			int l, r, x;
			input(l, r, x);
			s.update2(l - 1, r - 1, x);
		}
		else {
			int k, x;
			input(k, x);
			s.update(k - 1, {x, x});
		}
	}
}
