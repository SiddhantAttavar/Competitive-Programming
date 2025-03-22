#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
// #define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

#define ll long long
template<typename T, int SZ> struct SegTree {
	vector<T> seg; T id;
	T (*cmb) (T, T);
	SegTree(T _id, T _cmb(T, T)):id(_id),seg(2*SZ,id),cmb(_cmb){}
	void build() {for (int i=SZ-1; i >= 0; i--) seg[i]=cmb(seg[2*i],seg[2*i+1]);}
	template<typename B> ll query(int l, int r, int k, B ans, int s=0, int e=SZ-1, int c=1) {
		if (l > e || r < s) return 0ll;
		if (l <= s && r >= e) return ans(seg[c],k);
		int mid = (s + e) / 2;
		return query(l,r, k, ans, s, mid, 2*c) +
			query(l, r, k, ans, mid + 1, e, 2*c+1);
	}
	void update(int i, T x, int s=0, int e=SZ-1, int c=1) {
		if (s > i || e < i) return;
		if (s == e) {seg[c] = x; return;}
		int mid = (s + e) / 2;
		update(i, x, s, mid, 2*c);
		update(i, x, mid + 1, e, 2*c);
		seg[c] = cmb(seg[2*c], seg[2*c+1]);
	}
};

SegTree<vector<pair<int, ll>>, 1 << 17> t({}, [](vector<pair<int, ll>> a, vector<pair<int, ll>> b) {
	vector<pair<int, ll>> res;
	int i = 0, j = 0;
	ll x = 0;
	while (i < a.size() or j < b.size()) {
		if (i < a.size() and (j == b.size() or a[i].first < b[j].first)) {
			x += a[i].first;
			res.push_back({a[i].first, x});
			i++;
		}
		else {
			x += b[j].first;
			res.push_back({b[j].first, x});
			j++;
		}
	}
	return res;
});


int32_t main() {
	setup();

	int n, k;
	input(n, k);

	vector<int> a(n);
	arrput(a);
	rep(i, 0, n) {
		a[i] = max(a[i], 0);
	}

	rep(i, 0, n) {
		t.seg[i + (1 << 17)] = {{a[i], a[i]}};
	}
	t.build();

	int q;
	input(q);
	while (q--) {
		int l, r;
		input(l, r);
		l--;
		r--;

		int s = 0, e = 1e9, x = -1;
		while (s <= e) {
			int m = (s + e) / 2;
			int z = t.query(l, r, m, [](vector<pair<int, ll>> &a, int k) {
				return a.end() - lower_bound(a.begin(), a.end(), make_pair(k, -1ll));
			});
			if (z >= k) {
				x = m;
				s = m + 1;
			}
			else {
				e = m - 1;
			}
		}

		int z = t.query(l, r, x, [](vector<pair<int, ll>> &a, int k) {
			return a.end() - lower_bound(a.begin(), a.end(), make_pair(k, -1ll));
		});
		print(min(0, k - z) * x + t.query(l, r, x, [](vector<pair<int, ll>> &a, int k) {
			int i = lower_bound(a.begin(), a.end(), make_pair(k, -1ll)) - a.begin();
			if (i == 0) {
				return a.back().second;
			}
			return a.back().second - a[i - 1].second;
		}));
	}
}
