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
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int get(vi &a, vi &p, vi &x, vi &c, vi &v, int m) {
	int i = upper_bound(all(p), m) - p.begin() - 1;
	if (m == p[i]) {
		return x[i];
	}
	return x[i] + (m - p[i]) * v[a[i]];
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi c(n), v(n);
		arrput(c);
		arrput(v);

		vi a(n);
		iota(all(a), 0);
		sort(all(a), [&](int x, int y) {
			return v[x] > v[y];
		});

		vi p(n + 1, 0), x(n + 1, 0);
		rep(i, 0, n) {
			p[i + 1] = p[i] + c[a[i]];
			x[i + 1] = x[i] + c[a[i]] * v[a[i]];
		}

		int C = p.back(), V = x.back();
		int l = 1, r = C, res = C;
		while (l <= r) {
			int m = (l + r) / 2;
			if (get(a, p, x, c, v, m) * C >= (C - m) * V) {
				res = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		print(res);
	}
}
