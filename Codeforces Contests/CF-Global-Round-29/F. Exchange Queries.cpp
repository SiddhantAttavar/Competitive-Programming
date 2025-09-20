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
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

struct SegTree { // cmb(ID,b) = b
	vector<ordered_set> seg;
	SegTree(int n) {
		seg.resize(4 * n);
	}
	int get(int l, int r, int a, int b, int x, int y, int c) {
		if (r < a or l > b) {
			return 0;
		}
		if (a <= l and r <= b) {
			return seg[c].order_of_key({y, 1e18}) - seg[c].order_of_key({x, -1});
		}
		int m = (l + r) / 2;
		return get(l, m, a, b, x, y, 2 * c) + get(m + 1, r, a, b, x, y, 2 * c + 1);
	}
	void update(int l, int r, int i, int x, int y, int c) {
		if (r < i or l > i) {
			return;
		}
		seg[c].erase({x, i});
		seg[c].insert({y, i});
		if (l == r) {
			return;
		}
		int m = (l + r) / 2;
		update(l, m, i, x, y, 2 * c);
		update(m + 1, r, i, x, y, 2 * c + 1);
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vector<int> p(n), s(n);
		arrput(p);
		arrput(s);

		vector<int> a(n);
		rep(i, 0, n) {
			p[i]--;
			s[i]--;
			a[p[i]] = s[i];
		}

		SegTree t(n);

		rep(i, 0, n) {
			t.update(0, n - 1, i, 0, a[i], 1);
		}

		int res = 0;
		rep(i, 0, n) {
			res += i + 1 + t.get(0, n - 1, i + 1, n - 1, 0, a[i] - 1, 1);
		}

		while (q--) {
			int o, i, j;
			input(o, i, j);

			i = p[i - 1];
			j = p[j - 1];

			res -= t.get(0, n - 1, i + 1, n - 1, 0, a[i] - 1, 1) + t.get(0, n - 1, 0, i - 1, a[i] + 1, 1e18, 1);
			res -= t.get(0, n - 1, j + 1, n - 1, 0, a[j] - 1, 1) + t.get(0, n - 1, 0, j - 1, a[j] + 1, 1e18, 1);
			t.update(0, n - 1, i, a[i], a[j], 1);
			t.update(0, n - 1, i, a[j], a[i], 1);
			res += t.get(0, n - 1, i + 1, n - 1, 0, a[i] - 1, 1) + t.get(0, n - 1, 0, i - 1, a[i] + 1, 1e18, 1);
			res += t.get(0, n - 1, j + 1, n - 1, 0, a[j] - 1, 1) + t.get(0, n - 1, 0, j - 1, a[j] + 1, 1e18, 1);
			swap(a[i], a[j]);
			print(res);
		}
	}
}
