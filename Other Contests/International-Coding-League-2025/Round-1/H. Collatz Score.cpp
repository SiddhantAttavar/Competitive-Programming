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
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

template<typename T, int SZ> struct SegTree {
	vector<T> seg;
	T (*cmb) (T, T);
	SegTree(T _cmb(T, T)):seg(2*SZ),cmb(_cmb){}
	void build() {for (int i=SZ-1; i >= 0; i--) seg[i]=cmb(seg[2*i],seg[2*i+1]);}
	int answer(ordered_set &o, int k) {
		return o.size() - o.order_of_key(make_pair(k, -1));
	}
	int query(int l, int r, int k, int s=0, int e=SZ-1, int c=1) {
		if (l > e || r < s) return 0;
		if (l <= s && r >= e) return answer(seg[c], k);
		int mid = (s + e) / 2;
		return (query(l,r, k, s, mid, 2*c) +
			query(l, r, k, mid + 1, e, 2*c+1));
	}
	void change(int c, pair<int, int> x, pair<int, int> y) {
		int k = seg[c].size();
		seg[c].erase(x);
		seg[c].insert(y);
		assert(k == seg[c].size());
	}
	void update(int i, pair<int, int> x, pair<int, int> y, int s=0, int e=SZ-1, int c=1) {
		if (s > i || e < i) return;
		change(c, x, y);
		if (s == e) {return;}
		int mid = (s + e) / 2;
		update(i, x, y, s, mid, 2*c);
		update(i, x, y, mid + 1, e, 2*c+1);
	}
};

SegTree<ordered_set, 1 << 14> s([](ordered_set a, ordered_set b) {
	ordered_set o;
	for (pair<int, int> i : a) {
		o.insert(i);
	}
	for (pair<int, int> i : b) {
		o.insert(i);
	}
	return o;
});

int32_t main() {
	int N = 1e6;
	vector<int> dp(N + 1, 1e9);
	queue<int> qu;
	qu.push(1);
	dp[1] = 0;
	dp[0] = 0;
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();

		if (x == 100) {
			break;
		}

		if (2 * x <= N and dp[2 * x] == 1e9) {
			qu.push(2 * x);
			dp[2 * x] = dp[x] + 1;
		}
		if ((x - 1) % 3 == 0 and dp[(x - 1) / 3] == 1e9) {
			qu.push((x - 1) / 3);
			dp[(x - 1) / 3] = dp[x] + 1;
		}
	}

	int n, q;
	input(n, q);

	vector<int> a(n);
	arrput(a);

	ordered_set o;
	o.insert({1, 0});
	o.insert({1, 1});

	rep(i, 0, n) {
		ordered_set v;
		v.insert({dp[a[i]], i});
		s.seg[i + (1 << 14)] = v;
	}
	s.build();

	while (q--) {
		int o;
		input(o);

		if (o == 1) {
			int l, r, k;
			input(l, r, k);

			l--;
			r--;

			print(s.query(l, r, k));
		}
		else {
			int i;
			input(i);
			i--;
			s.update(i, {dp[a[i]], i}, {dp[a[i] + 1], i});
			a[i]++;
		}
	}
}
