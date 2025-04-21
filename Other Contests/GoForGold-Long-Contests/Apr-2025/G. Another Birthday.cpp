#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		vector<int> p(n);
		p[0] = max(0ll, a[0]);
		int x = 0;
		rep(i, 1, n) {
			x = max(0ll, x + a[i]);
			p[i] = max(p[i - 1], x);
		}

		vector<int> s(n);
		s[n - 1] = max(0ll, a[n - 1]);
		x = 0;
		for (int i = n - 2; i >= 0; i--) {
			x = max(0ll, x + a[i]);
			s[i] = max(s[i + 1], x);
		}

		int res = p[n - 1];
		x = 0;
		rep(i, 0, n - 1) {
			x += a[i];
			res = max(res, x + s[i + 1]);
		}

		x = 0;
		for (int i = n - 1; i > 0; i--) {
			x += a[i];
			res = max(res, x + p[i - 1]);
		}

		vector<int> q(n);
		q[0] = min(0ll, a[0]);
		x = 0;
		rep(i, 1, n) {
			x = min(0ll, x + a[i]);
			q[i] = min(q[i - 1], x);
		}

		vector<int> r(n);
		r[n - 1] = min(0ll, a[n - 1]);
		x = 0;
		for (int i = n - 2; i >= 0; i--) {
			x = min(0ll, x + a[i]);
			r[i] = min(r[i + 1], x);
		}

		x = accumulate(a.begin(), a.end(), 0ll);
		rep(i, 0, n - 1) {
			res = max(res, x - q[i] - r[i + 1]);
		}

		print(res);
	}
}
