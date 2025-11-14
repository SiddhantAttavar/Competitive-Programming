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

int getmin(vector<int> &x, vector<int> &c) {
	int a = -1e18;
	rep(i, 0, x.size()) {
		a = max(a, -c[i] - x[i]);
	}
	return a;
}

int getmax(vector<int> &x, vector<int> &c) {
	int a = -1e18;
	rep(i, 0, x.size()) {
		a = max(a, -c[i] + x[i]);
	}
	return a;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> x(n), y(n), c(n);
		arrput(x);
		arrput(y);
		arrput(c);
		rep(i, 0, n) {
			x[i] *= 2;
			y[i] *= 2;
		}

		int k = accumulate(c.begin(), c.end(), 0ll);
		int a = getmin(x, c), b = getmax(x, c);
		int p = getmin(y, c), q = getmax(y, c);

		int res = k + a + b + p + q;
		res = max(res, k - *min_element(c.begin(), c.end()));
		rep(i, 0, n) {
			res = max(res, k - c[i] + max(-x[i] + b, x[i] + a) + max(-y[i] + q, y[i] + p));
		}

		vector<int> v = y;
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		map<int, int> m;
		rep(i, 0, v.size()) {
			m[v[i]] = i;
		}

		vector<tuple<int, int, int>> l(n);
		rep(i, 0, n) {
			l[i] = {x[i], y[i], c[i]};
		}
		sort(l.begin(), l.end());
		int s = -1e18, t = -1e18;
		for (auto [x, y, c] : l) {
			res = max(res, k + s + y + x - c);
			s = max(s, -x - y - c);
			res = max(res, k + t - y + x - c);
			t = max(t, -x + y - c);
		}

		print(res);
	}
}
