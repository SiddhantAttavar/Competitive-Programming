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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

bool check(vector<int> &x, vector<int> &y, int k, int m) {
	int c = (x.size() + y.size()) / 2 + 1;
	c -= y.end() - lower_bound(y.begin(), y.end(), m);
	if (c > (int) x.size()) {
		return false;
	}
	rep(i, 0, c) {
		k -= max(0ll, m - x[i]);
	}
	return k >= 0;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n), b(n);
		arrput(a);
		arrput(b);

		int u = -1;
		rep(i, 0, n) {
			if (b[i] and (u == -1 or a[i] > a[u])) {
				u = i;
			}
		}

		int res = 0;
		if (u != -1) {
			vector<int> c = a;
			c.erase(c.begin() + u);
			sort(c.begin(), c.end());
			res = max(res, c[n / 2 - 1] + a[u] + k);
		}

		vector<int> x, y;
		rep(i, 0, n) {
			if (b[i]) {
				x.push_back(a[i]);
			}
			else {
				y.push_back(a[i]);
			}
		}
		sort(x.begin(), x.end());
		reverse(x.begin(), x.end());
		sort(y.begin(), y.end());

		if (y.empty()) {
			print(res);
			continue;
		}

		int z = y.back();
		y.pop_back();
		res = max(res, z);

		int l = 0, r = 3e9;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(x, y, k, m)) {
				res = max(res, z + m);
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		print(res);
	}
}
