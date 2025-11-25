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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k, q;
		input(n, k, q);

		vector<pair<int, int>> x, y;
		while (q--) {
			int c, l, r;
			input(c, l, r);

			l--;
			r--;
			if (c == 1) {
				x.push_back({l, r});
			}
			else {
				y.push_back({l, r});
			}
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());

		vector<bool> b(n, false), c(n, false);
		for (auto [l, r] : x) {
			rep(i, l, r + 1) {
				b[i] = true;
			}
		}
		for (auto [l, r] : y) {
			rep(i, l, r + 1) {
				c[i] = true;
			}
		}

		vector<int> a(n, -1);
		rep(i, 0, n) {
			if (b[i] and c[i]) {
				a[i] = k + 1;
			}
			else if (b[i]) {
				a[i] = k;
			}
		}

		for (auto [l, r] : y) {
			vector<bool> x(k, false);
			rep(i, l, r + 1) {
				if (a[i] >= 0 and a[i] < k) {
					x[a[i]] = true;
				}
			}

			int c = 0;
			rep(i, l, r + 1) {
				if (a[i] != -1) {
					continue;
				}
				while (c < k and x[c]) {
					c++;
				}
				if (c < k) {
					a[i] = c;
					x[c] = true;
				}
			}
		}

		rep(i, 0, n) {
			if (a[i] == -1) {
				a[i] = 0;
			}
		}
		arrprint(a);
	}
}
